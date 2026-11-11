// pet: make one struct on the heap, use it, and free it. (Tutor demo, write it together.)
//
// Steps:
//   1. pet_new():  calloc() one Pet, fill in its fields with ->, return the pointer.
//   2. main():     make two pets, print them, change one, print it again.
//   3. pet_free(): free one Pet. Then main sets its pointer to NULL.
//
// The correct result:
//   $ clang -Wall -Werror pet.c -o pet && ./pet
//   Mochi is 3 years old.
//   Biscuit is 7 years old.
//   Mochi is 4 years old.
//   freed Mochi
//   freed Biscuit
//
// Talk about: why not `Pet p;` and return &p? What does calloc() set the fields to?
// Why sizeof(Pet) and not sizeof(Pet *)? What is p after free(p)?
#include <stdio.h>
#include <stdlib.h>

// Do not modify this type.
typedef struct s_pet Pet;

struct s_pet {
    const char *name;
    int age;
};

// Step 1: returns a pointer to a new Pet on the heap.
Pet *pet_new(const char *name, int age) {
    return NULL;
}

// Step 3: prints "freed NAME", then frees the Pet.
void pet_free(Pet *p) {
}

int main(void) {
    // Step 2: make Mochi (3) and Biscuit (7), print both, make Mochi a year older,
    // print Mochi again. Then free both and set the pointers to NULL.

    return 0;
}
