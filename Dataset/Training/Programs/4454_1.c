#include <stdio.h>
#include <stdlib.h>

// Prototypes for verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 5, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// Nondeterministic input functions
extern int __VERIFIER_nondet_int(void);

// The main logic of the program
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume some conditions to aid verification
    assume_abort_if_not(a > 0 && b > 0);

    int sum = 0;
    int counter = 0;

    // Loop to accumulate sum with constraints
    while (counter < 10) {
        sum += a + b;
        __VERIFIER_assert(sum >= (a + b) * (counter + 1));

        if (sum > 100) {
            break;
        }

        counter++;
    }

    // Post-condition assertions

    // Final output
    printf("Final sum: %d\n", sum);
    printf("Counter: %d\n", counter);

    return 0;
}