#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 6, "reach_error"); }
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
    int n, sum, count;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10000);

    sum = 0;
    count = 0;

    while (count < n) {
        if (count % 2 == 0) {
            sum += count * count; // sum of squares of even numbers
        } else if (count % 3 == 0) {
            sum += count * 3; // thrice the count if multiples of 3
        } else {
            sum += count; // otherwise just add the count
        }
        count++;
    }

    // Check if sum is reasonable given the bounds of the loop
    // Ensure we have processed exactly 'n' iterations
    __VERIFIER_assert(count == n);

    return 0;
}