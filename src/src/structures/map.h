/**
 * defines necessary structures and functions for a hashmap
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

#ifndef __MAP__
#define __MAP__

#include "linkedlist.h"
#include <stddef.h>

/**
 * structure for a key value pair
 */
typedef struct {
    /**
     * the key
     */
    void* key;
    /**
     * the value associated with the key
     */
    void* value;
} KeyValuePair;

/**
 * structure for a hashmap
 */
typedef struct {
    /**
     * array that holds map data
     */
    LinkedList** data_array;
    /**
     * current capacity of the map
     */
    unsigned int capacity;
    /**
     * current number of elements of the map
     */
    unsigned int num_elements;
} Map;

/**
 * allocates a new map
 */
Map* map_create(unsigned int initial_capacity);

/**
 * puts a new element data into the map with the given key or updates it if the element
 * with the given key already exists
 */
void map_put(Map* m, void* key, int (*hashfunc)(void*), int (*keycompfunc)(void*, void*), void* data);

/**
 * returns the element associated with a given key if it exists, NULL otherwise
 */
void* map_get(Map* m, void* key, int (*hashfunc)(void*), int (*keycompfunc)(void*, void*));

/**
 * removes the element with associated with the given key and returns it, returns NULL
 * if it doesnt exist
 */
void* map_remove(Map* m, void* key, int (*hashfunc)(void*), int (*keycompfunc)(void*, void*), void (*keyfree)(void*));

/**
 * returns 1 if the key exists in the map
 */
int map_contains_key(Map* m, void* key, int (*hashfunc)(void*), int (*keycompfunc)(void*, void*));

/**
 * allocates and returns an array of the keys of the hash map
 */
void** map_keys(Map* m);

/**
 * allocates and returns an array of the values of the hash map
 */
void** map_values(Map* m);

/**
 * allocates and returns an array of references to KeyValuePairs of the hash map
 */
KeyValuePair** map_kvps(Map* m);

/**
 * returns the size of the hash map
 */
unsigned int map_size(Map* m);

/**
 * frees all data from the hash map, using the freefunc
 */
void map_clear(Map* m, void (*freefunc)(void *), void (*keyfree)(void*));

/**
 * frees the data associated with the hash map
 */
void map_destroy(Map* m);

#endif