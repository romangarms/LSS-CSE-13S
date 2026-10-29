// Two string functions that use strchr().
//
// Goal:
//   ./secret    prints   all tests passed
//
// Fill in has_any() and censor() until every test passes. Use strchr() for the
// "is this char in that string?" part of each one, instead of writing that loop yourself.
//
//   has_any(s, chars)    true if s has at least one char that is also in chars
//   censor(s, hide)      changes every char of s that is in hide to '*'
//
// Hints:
//   Read about it with:  man 3 strchr   (q quits). What does it return when the char is NOT found?
//   Which string do you loop over, and which one do you hand to strchr()?
//   s[i] is one char of s, and you can store into it like any variable.
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool has_any(const char *s, const char *chars) {
    // your code here
    return false;
}

void censor(char s[], const char *hide) {
    // your code here
}

// Do not modify this function.
int main(void) {
    const char *symbols = "!@#$%";
    assert(has_any("hunter2", symbols) == false);
    assert(has_any("hunter2!", symbols) == true);
    assert(has_any("#1 fan", symbols) == true);
    assert(has_any("", symbols) == false);
    assert(has_any("13S", "0123456789") == true);

    char msg[] = "meet at noon";
    censor(msg, "aeiou");
    assert(strcmp(msg, "m**t *t n**n") == 0);

    char pin[] = "my pin is 4821";
    censor(pin, "0123456789");
    assert(strcmp(pin, "my pin is ****") == 0);

    char same[] = "nothing to hide";
    censor(same, "xyz");
    assert(strcmp(same, "nothing to hide") == 0);

    printf("all tests passed\n");
    return 0;
}
