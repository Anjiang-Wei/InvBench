#include <stdio.h>
#include <stdlib.h>

/*
A Simple Linear Search
Searches for a target value within an array and verifies that the value is present.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "linear_search.c", 9, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int __VERIFIER_nondet_int();
_Bool __VERIFIER_nondet_bool();

#define SIZE 10

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int array[SIZE];
    int target, i, found;

    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    target = __VERIFIER_nondet_int();

    i = 0;
    found = 0;

    // Linear search
    while (i < SIZE) {
        if (array[i] == target) {
            found = 1;
            break;
        }
        i++;
    }

    // Check that target was found if found is 1
    if (found) {
        __VERIFIER_assert(array[i] == target);
    } else {
        // Check that target is not in the array
        for (int j = 0; j < SIZE; j++) {
        }
    }

    return 0;
}