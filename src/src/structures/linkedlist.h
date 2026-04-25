/**
 * defines necessary structures and functions for a linked list
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
#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stddef.h>

/**
 * node structure for a linked list
 */
typedef struct {
    /**
     * data of a node
     */
    void* data;
    /**
     * next pointer of a node
     */
    void* next;
} Node;

/**
 * linked list structure
 */
typedef struct {
    /**
     * front of the linked list
     */
    Node* head;
    /**
     * total number of elements in the linked list
     */
    unsigned int size;
} LinkedList;

/**
 * creates a new linked list, initializes it, and returns it
 */
LinkedList *ll_create();

/**
 * adds the item data to the front of the linked list
 */
void ll_push(LinkedList *l, void *data);

/**
 * removes the front element from the linked list and returns the associated data
 */
void *ll_pop(LinkedList *l);

/**
 * adds the item data to the end of the linked list
 */
void ll_append(LinkedList *l, void *data);

/**
 * removes the first node in the list whose data matches target given the comparison function
 * returns the pointer to the data in the removed node
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

/**
 * finds the first node in the list whose data matches target given the comparison function 
 *  returns the pointer to the data in the node if found, otherwise returns NULL
 */
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *));

/**
 * returns the size of the linked list
 */
unsigned int ll_size(LinkedList *l);

/**
 * removes all of the nodes from the list, freeing the associated data using the given function
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *));

/**
 * traverses the list and applies the given function to the data at each node
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *));

#endif