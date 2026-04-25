/**
 * implementation for the console memory structure
 * Copyright (C) 2026  Brooke Vincent
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "conmem.h"
#include "../structures/map.h"
#include "../util/hash.h"
#include "../util/comp.h"
#include <stdlib.h>
#include <stdio.h>

MemHandler* conmem_handler;

const unsigned int MEMORY_AMOUNT = 8388608; // 8MB


/**
 * does nothing
 */
void false_free(void* data){
    return;
}

/**
 * initializes the memory handler for the console
 */
void conmem_init(){
    conmem_handler = (MemHandler*) malloc(sizeof(MemHandler));
    conmem_handler->memory = map_create(16);
    conmem_handler->memory_used = 0;
}

/**
 * allocates new memory to the console memory, setting all bytes to zero
 */
void conmem_alloc(void** pointer, unsigned int size){
    
    MemBlock* new_block = (MemBlock*) malloc(sizeof(MemBlock));
    new_block->references = 1;
    new_block->size = size;
    
    //handle change of references
    MemBlock* associated = map_get(conmem_handler->memory, *pointer, pointer_hash, pointer_comp);

    if (associated != NULL){
        associated->references--;
    }

    *pointer = malloc(size);

    map_put(conmem_handler->memory, *pointer, pointer_hash, pointer_comp, new_block);

    conmem_handler->memory_used += size;
}

/**
 * deallocates a pointer
 */
void conmem_free(void* pointer){
    MemBlock* associated = map_remove(conmem_handler->memory, pointer, pointer_hash, pointer_comp, false_free);

    if(associated != NULL){
        conmem_handler->memory_used -= associated->size;
        free(associated);
        free(pointer);
    }
}

/**
 * associates a pointer with a new pointer
 */
void conmem_assoc(void** pointer, void* to_point_to){
    //handle change of references
    MemBlock* old_associated = map_get(conmem_handler->memory, *pointer, pointer_hash, pointer_comp);

    if (old_associated != NULL){
        old_associated->references--;
    }

    MemBlock* new_associated = map_get(conmem_handler->memory, to_point_to, pointer_hash, pointer_comp);

    if(new_associated != NULL){
        new_associated->references++;
        *pointer = to_point_to;
    }
    else{
        *pointer = NULL;
    }
}

/**
 * deassociate a pointer from its target, sets the pointer to NULL
 */
void conmem_dessoc(void** pointer){
    //handle change of references
    MemBlock* old_associated = map_get(conmem_handler->memory, *pointer, pointer_hash, pointer_comp);

    if (old_associated != NULL){
        old_associated->references--;
    }

    *pointer = NULL;
}

/**
 * cleans any memory units that have no references
 */
void conmem_clean(){
    unsigned int number_allocated = map_size(conmem_handler->memory);
    KeyValuePair** allocated_pairs = map_kvps(conmem_handler->memory);

    for(unsigned int i = 0; i < number_allocated; i++){
        if(((MemBlock*) allocated_pairs[i]->value)->references == 0){
            conmem_free(allocated_pairs[i]->key);
        }
    }
}

/**
 * destroy the memory handler
 */
void conmem_destroy(){
    //TODO: clean allocated memory
    conmem_clean();
    map_destroy(conmem_handler->memory);
    free(conmem_handler);
}

