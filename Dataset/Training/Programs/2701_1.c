#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "linear_search.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void exit(int);

#define ARRAY_SIZE 10

// Array elements are assumed to be within this range for constraint purposes
#define MIN_VALUE 0
#define MAX_VALUE 100

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int array[ARRAY_SIZE];
    int i, key, found = 0;

    // Initialize array with nondeterministic values within range
    for (i = 0; i < ARRAY_SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(array[i] >= MIN_VALUE && array[i] <= MAX_VALUE);
    }

    // Nondeterministic choice of search key
    key = __VERIFIER_nondet_int();
    assume_abort_if_not(key >= MIN_VALUE && key <= MAX_VALUE);

    // Bounded linear search: check if key exists in the array
    for (i = 0; i < ARRAY_SIZE; i++) {
        if (array[i] == key) {
            found = 1;
            break;
        }
    }

    // Assertion: If found is set, key should exist in the array
    if (found) {
        int check = 0;
        for (i = 0; i < ARRAY_SIZE; i++) {
            if (array[i] == key) {
                check = 1;
                break;
            }
        }
        __VERIFIER_assert(check);
    }

    return 0;
}