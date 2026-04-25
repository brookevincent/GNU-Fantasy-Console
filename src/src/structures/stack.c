/**
 * implementation of a generic c stack
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

#include "stack.h"

/**
 * returns a reference to an allocated stack.
 */
Stack *stk_create(unsigned int capacity){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->data = (void**) malloc(sizeof(void**) * capacity);
    s->top = s->data;
    s->capacity = capacity;

    return s;
}

/**
 * frees all space allocated for the stack.
 *
 * does not deallocate the space given to the items referenced by the stack.
 */
void stk_destroy(Stack *stack){
    free(stack->data);
    free(stack);
}

/**
 * returns the number of items in the given stack.
 */
unsigned int stk_size(Stack *stack){
    return (unsigned int) (stack->top - stack->data);
}

/**
 * adds the given item to the top of the given stack.
 */
void stk_push(Stack *stack, void *item){
    *(stack->top) = item;
    stack->top++;

    //allocate more memory to stack
    if (stack->top > stack->data + stack->capacity){
        unsigned int new_capacity = 2 * stack->capacity;
        stack->data = (void**) realloc(stack->data, sizeof(void**) * new_capacity);

        stack->top = stack->data + new_capacity;

        stack->capacity = new_capacity;
    }
}

/**
 * returns a reference to the item on top of the stack.
 */
void *stk_peek(Stack *stack){
    return *(stack->top - 1);
}

/**
 * removes the top item of the stack and returns a reference to it.
 */
void *stk_pop(Stack *stack){
    void* out = *(stack->top - 1);
    stack->top--;
    return out;
}