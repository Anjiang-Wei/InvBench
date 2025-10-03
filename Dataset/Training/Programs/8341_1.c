// New C program based on learned patterns and structures

#include <stdio.h>
#include <stdlib.h>

// Assertion functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 13, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
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

int counter = 0;

int main() {
    int n, a, b, c, sum;
    n = __VERIFIER_nondet_int();

    a = 0;
    b = 1;
    sum = 0;

    // Loop that simulates Fibonacci calculation and checks constraint
    while (counter++ < 10) {
        // Fibonacci-like computation
        c = a + b;
        a = b;
        b = c;

        // Sum of even numbers in Fibonacci sequence
        if (c % 2 == 0) {
            sum += c;
        }

        // Constraint ensuring sum is positive and smaller than a certain upper bound
        __VERIFIER_assert(sum >= 0 && sum < 1000);

        // Break when n iterations are complete or sum exceeds upper bound
        if (sum >= 1000 || n <= 0) {
            break;
        }
        n = n - 1;
    }

    printf("Final sum of even Fibonacci numbers: %d\n", sum);
    return 0;
}