# conmem

File for handling console memory along with garbage 
collection.

Garbage collection is handled via reference counting.

## Structs

### Memblock

Contains all information relating to a block of memory.

*size* - unsigned int - size of the memory block.

*references* - unsigned int - number of references the
block has.

### MemHandler

Contains all functions needed for the memory system of the
console memory.

*memory* - Map* - memory of the console

*memory_used* - unsigned int - amount of memory used thus 
far

## Functions

### void conmem_init()

Initializes the console memory.

### void conmem_alloc(void** pointer, unsigned int size)

Allocates a block of memory to the console.

Parameters
 - *pointer* - void** - pointer to the pointer to allocate 
    to.
 - *size* - unsigned int - the size of the block to 
    allocate

### void conmem_free(void* pointer)

Frees a memory block.

Parameters
 - *pointer* - void* - pointer to the block to deallocate


### void conmem_assoc(void** pointer, void* to_point_to)

Associates a pointer to a memory block.

Parameters
 - *pointer* - void** - the pointer to associate to
 - *to_point_to* - void* - pointer to the memory block to
    associate pointer to

### void conmem_dessoc(void** pointer)

Deassociates a pointer from a memory block. Sets the 
pointer to NULL.

Parameters
 - *pointer* - void** - pointer to deassociate

### void conmem_clean()

Cleans any memory blocks without any references.

### void conmem_destroy()

Destroys the memory handler.