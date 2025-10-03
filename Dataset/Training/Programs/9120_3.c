#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_new.c", 6, "reach_error"); }

// Function to mimic nondeterministic integer generation
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = 0;
    int b = 100;
    int step = __VERIFIER_nondet_int();

    // Assuming `step` should be a positive integer
    if (step <= 0) {
        step = 1; // Default step value
    }

    while (a < b) {
        a += step;
        if (a >= b) {
        }
    }

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += i;
    }

    sum = 0;
    a = 0;
    while (a < 10) {
        sum += a;
        a++;
    }
    __VERIFIER_assert(sum == 45);

    return 0;
}