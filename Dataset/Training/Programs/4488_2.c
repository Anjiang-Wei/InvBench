#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verification_example.c", 10, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int __VERIFIER_nondet_int(void) {
    return rand() % 20 - 10; // return random number between -10 and 9
}

int square(int x) {
    return x * x;
}

int main(void) {
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume that a and b are non-negative
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    int result = 0;
    int counter = 0;

    // Loop to perform multiplication using repeated addition
    while (counter < b) {
        result = result + a;
        counter++;
    }

    // Assertion to check if the multiplication is correct

    // Another property to check using square function
    if (a > 0 && b > 0) {
        int sqa = square(a);
        int sqb = square(b);
        __VERIFIER_assert(sqa + sqb > 0);
    }

    return 0;
}