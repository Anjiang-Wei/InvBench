#include <stdio.h>
#include <stdlib.h>

// Function to be used in case of a logical error
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 6, "reach_error"); }

// Function to get nondeterministic values
extern int __VERIFIER_nondet_int(void);

// Function to assert a condition with an error if the condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x, y, a, b, count;

    // Get nondeterministic values
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && x <= 1000);
    assume_abort_if_not(y >= 0 && y <= 1000);

    // Initialize variables
    a = 0;
    b = 0;
    count = 0;

    while (count < x + y) {
        if (a < x) {
            a++;
        }
        if (b < y) {
            b++;
        }
        count++;
    }

    // Check conditions
    __VERIFIER_assert(count == x + y);

    return 0;
}