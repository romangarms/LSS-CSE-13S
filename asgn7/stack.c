/*
*
* CSE 13S - Fall 2026 - Assignment 7
*
* stack.c
*
*/

#include "stack.h"

#include <assert.h>
#include <stdlib.h>

typedef struct stack {
    int capacity;       // Maximum number of items in the stack.

    int num_items;      // The number of items in the stack.
                        // Also, the index of the next free space.

    int *items;         // Array of ints that are in the stack.
} Stack;

/*
* Purpose:      Create a Stack
* Parameter:    Maximum number of items that can be in the stack.
* Returns:      A pointer to the new stack.
*/
Stack *stack_create(int capacity) {
    // Attempt to allocate memory for a stack
    Stack *s = calloc(1, sizeof(Stack));
    assert(s);

    s->num_items = 0;
    s->capacity = capacity;
    // We need enough memory for <capacity> numbers
    s->items = calloc(capacity, sizeof(int));
    assert(s->items);

    // We created our stack, return it!
    return s;
}

/*
* Purpose:      Free a Stack
*
* Parameter:    A pointer to a pointer to a Stack.
*
*               First, free the stack at *sp.  After that, set *sp to NULL.
*
* Returns:      Nothing
*/
void stack_free(Stack **sp) {
    // sp is a double pointer, so we have to check if it,
    // or the pointer it points to is null;
    if (sp != NULL && *sp != NULL) {
        // Of course, we have to remember to free the
        // memory for the array of items first,
        // as that was also dynamically allocated!
        if ((*sp)->items) {
            free((*sp)->items);
            (*sp)->items = NULL;
        }
        // Free memory allocated for the stack
        free(*sp);
    }
    // Set the pointer to null! This ensures we dont ever do a double free!
    if (sp != NULL) {
        *sp = NULL;
    }
}

/*
* Purpose:      Push an int on the stack.
* Parameters:   A pointer to a Stack and the int to push.
* Returns:      false if the stack is full; true otherwise.
*/
bool stack_push(Stack *s, int val) {
    if (stack_full(s)) {
        return false;
    }

    // Set val
    s->items[s->num_items] = val;

    // Move the top of the stack.
    s->num_items++;

    return true;
}

bool stack_pop(Stack *s, int *val) {
    return false; // TODO
}

bool stack_peek(const Stack *s, int *val) {
    return false; // TODO
}

bool stack_empty(const Stack *s) {
    return false; // TODO
}

bool stack_full(const Stack *s) {
    return false; // TODO
}

int stack_size(const Stack *s) {
    return 0; // TODO
}

void stack_copy(Stack *dst, const Stack *src) {
    // TODO
}

/*
* Purpose:      Print the items of a Stack
* Parameters:   A pointer to a Stack, the output file, and an array of city
*               names to identify each item of the stack.
* Returns:      Nothing
*/
void stack_print(const Stack *s, FILE *outfile, char *cities[]) {
    for (int i = 0; i < s->num_items; i += 1) {
        fprintf(outfile, "%s\n", cities[s->items[i]]);
    }
}

