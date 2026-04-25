/**
 * implements hash functions for various types
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


#include "hash.h"

/**
 * hashes a pointer
 */
int pointer_hash(void* ptr){
    int out = 0;
    for(int i = 0; i < sizeof(void*); i++){
        out += ((char* ) ptr)[i] * 257;
    }
    return out;
}