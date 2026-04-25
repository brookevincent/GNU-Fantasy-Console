/**
 * implementation for the linked list structure
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

#include "linkedlist.h"
#include <stdlib.h>

/**
 * creates a new linked list, initializes it, and returns it
 */
LinkedList *ll_create(){
    //allocate memory
    LinkedList* out = (LinkedList*) malloc(sizeof(LinkedList));

    //initialize fields 
    out->head = NULL;
    out->size = 0;

    return out;
}

/**
 * adds the item data to the front of the linked list
 */
void ll_push(LinkedList *l, void *data){
    //allocate and set up new node
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = l->head;

    //replace linked list head
    l->head = new_node;

    //increase size
    l->size++;
}

/**
 * removes the front element from the linked list and returns the associated data
 */
void *ll_pop(LinkedList *l){
    //catch empty list case
    if (l->head == NULL){
        return NULL;
    }

    //get current head data
    Node* out_node = l->head;
    
    //replace head element
    l->head = l->head->next;

    //free node
    void* out = out_node->data;
    free(out_node);

    //decrease size
    l->size--;
    return out;
}

/**
 * adds the item data to the end of the linked list
 */
void ll_append(LinkedList *l, void *data){
    //allocate and set up new node
    Node* new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node->next = NULL;
    
    //catch empty list case
    if (l->head == NULL){
        l->head = new_node;
        l->size++;
        return;
    }
    //traverse linked list
    Node* cur = l->head;

    while(cur->next != NULL) cur = cur->next;

    //append new node
    cur->next = new_node;

    //increase size
    l->size++;
}

/**
 * removes the first node in the list whose data matches target given the comparison function
 * returns the pointer to the data in the removed node
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){

    //catch empty list case
    if (l->head == NULL){
        return NULL;
    }

    //traverse linked list
    Node* cur = l->head;
    Node* prev = NULL;

    while( cur->next != NULL && !compfunc(target, cur->data)){
        prev = cur;
        cur = cur->next;

    }

    if (compfunc(target, cur->data)){
        //extract data
        Node* out_node = cur;

        //replace references
        if (prev == NULL) l->head = cur->next;
        else prev->next = cur->next;

        //free node
        void* out = out_node->data;
        free(out_node);

        l->size--;

        return out;
    }
    else return NULL;
}

/**
 * finds the first node in the list whose data matches target given the comparison function 
 *  returns the pointer to the data in the node if found, otherwise returns NULL
 */
void *ll_find(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
    //catch empty list case
    if (l->head == NULL){
        return NULL;
    }

    //traverse linked list
    Node* cur = l->head;

    while( cur->next != NULL && compfunc(target, cur->data) != 0){
        cur = cur->next;
    }

    if (compfunc(target, cur->data) == 0) return cur->data;
    else return NULL;
}

/**
 * returns the size of the linked list
 */
unsigned int ll_size(LinkedList *l){
    return l->size;
}

/**
 * removes all of the nodes from the list, freeing the associated data using the given function
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *)){
    //handle empty list case
    if (l->head == NULL){
        return;
    }

    //traverse list
    Node* cur = l->head;
    Node* next;

    while (cur != NULL){
        next = cur->next;

        //free data
        freefunc(cur->data);
        free(cur);

        cur = next;
    }

    l->head = NULL;
    l->size = 0;

}

/**
 * traverses the list and applies the given function to the data at each node
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *)){
    //handle empty list case
    if (l->head == NULL){
        return;
    }

    //traverse list
    Node* cur = l->head;

    while (cur != NULL){
        
        //map data
        mapfunc(cur->data);

        cur = cur->next;
    }
}