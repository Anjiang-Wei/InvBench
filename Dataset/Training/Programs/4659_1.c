#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "my_program.c", 6, "reach_error"); }
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

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int total_sum = 0;
    int loop_counter = 0;

    // Assume x and y are positive integers
    assume_abort_if_not(x > 0 && y > 0);

    while (loop_counter < 10) {
        loop_counter++;
        total_sum += (x + y);

        // Simulate some operation with constraints
        if (total_sum > 100) {
            total_sum -= 50;
        } else {
            total_sum += 5;
        }

        // Verification of essential properties
        __VERIFIER_assert(total_sum >= 0); // Ensure total_sum never becomes negative
    }

    // Ensure loop processed correctly
    __VERIFIER_assert(loop_counter == 10);

    printf("Final Total Sum: %d\n", total_sum);
    return 0;
}