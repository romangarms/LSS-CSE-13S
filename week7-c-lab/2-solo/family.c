// family: builds a small family tree, counts it, then frees it.
// Each Person points to their mom and dad (NULL if unknown), so it's a binary tree,
// just like asgn6's Node with left and right.
//
// Write the 3 functions marked "Write this", in order:
//   Part 1  person_new()    allocate a Person with calloc() and fill in its name
//   Part 2  count_people()  recursion: count everyone in the tree
//   Part 3  free_family()   free every Person, and print "free NAME" just before each free()
// Until Part 1 works, the program crashes (main uses the pointers person_new() returns).
//
// The correct result:
//   $ clang -Wall -Werror family.c -o family && ./family
//   Sam's family tree has 7 people.
//   free Fay
//   free Cora
//   free Dev
//   free Ana
//   free Eve
//   free Ben
//   free Sam
//
// Hints: person_new() works like pet_new() from the demo. Each recursive function needs a
// base case for NULL. Spec section 2.3 says which traversal order to use for freeing.
#include <stdio.h>
#include <stdlib.h>

// Do not modify this type.
typedef struct s_person Person;

struct s_person {
    const char *name;   // the person's name
    Person *mom;        // pointer to their mom, or NULL
    Person *dad;        // pointer to their dad, or NULL
};

// Write this (Part 1).
// Returns a pointer to a new Person on the heap with this name and no mom or dad.
Person *person_new(const char *name) {
    return NULL;
}

// Write this (Part 2).
// Returns how many people are in the tree that starts at p (p, plus all of p's ancestors).
int count_people(Person *p) {
    return 0;
}

// Write this (Part 3).
// Frees every Person in the tree that starts at p. Print "free NAME" before each free().
void free_family(Person *p) {
}

// Do not modify main().
int main(void) {
    Person *sam = person_new("Sam");
    sam->mom = person_new("Ana");
    sam->dad = person_new("Ben");
    sam->mom->mom = person_new("Cora");
    sam->mom->dad = person_new("Dev");
    sam->dad->mom = person_new("Eve");
    sam->mom->mom->mom = person_new("Fay");

    printf("%s's family tree has %d people.\n", sam->name, count_people(sam));

    free_family(sam);
    sam = NULL;
    return 0;
}
