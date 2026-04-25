/**
 * header file for defining functions that act on the console's memory
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

#ifndef __CONMEM__
#define __CONMEM__
#include "../structures/map.h"

/**
 * structure for a memory block
 */
typedef struct {
    /**
     * size of the block
     */
    unsigned int size;
    /**
     * number of references to the block
     */
    unsigned int references;
} MemBlock;

 /**
 * structure for the console memory handler
 */
typedef struct 
{
    /**
     * pointer to the memory region
     */
    Map* memory;
    /**
     * amount of memory used
     */
    unsigned int memory_used;

} MemHandler;

/**
 * initializes the memory handler for the console
 */
void conmem_init();

/**
 * allocates new memory to the console memory, setting all bytes to zero
 */
void conmem_alloc(void** pointer, unsigned int size);

/**
 * deallocates a pointer
 */
void conmem_free(void* pointer);

/**
 * associates a pointer with a new pointer
 */
void conmem_assoc(void** pointer, void* to_point_to);

/**
 * deassociate a pointer from its target, sets the pointer to NULL
 */
void conmem_dessoc(void** pointer);

/**
 * cleans any memory units that have no references
 */
void conmem_clean();

/**
 * destroy the memory handler
 */
void conmem_destroy();

#endif