/**
 * definition for generic stack and the functions that act on one
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

#ifndef __STACK__
#define __STACK__

#include <stdlib.h>

typedef struct {
    void **data;
    void **top;
    unsigned int capacity;
} Stack;

/**
 * returns a reference to an allocated stack.
 */
Stack *stk_create(unsigned int capacity);

/**
 * frees all space allocated for the stack.
 *
 * does not deallocate the space given to the items referenced by the stack.
 */
void stk_destroy(Stack *stack);

/**
 * returns the number of items in the given stack.
 */
unsigned int stk_size(Stack *stack);

/**
 * adds the given item to the top of the given stack.
 */
void stk_push(Stack *stack, void *item);

/**
 * returns a reference to the item on top of the stack.
 */
void *stk_peek(Stack *stack);

/**
 * removes the top item of the stack and returns a reference to it.
 */
void *stk_pop(Stack *stack);

#endif