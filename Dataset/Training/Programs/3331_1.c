#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
#define MAX_COUNTER 100

int main() {
    int a, b, c, sum;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assumes non-negative input
    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);

    sum = 0;

    while (counter++ < MAX_COUNTER) {
        // Perform some computations on a, b, c to simulate real processing
        sum += a;
        a = a + b + 1;
        b = (b + c) / 2;
        c = c - 1;

        // Avoid a from exceeding a certain limit
        assume_abort_if_not(a < MAX_COUNTER * 10);

        // Break if meaningful condition after some operations
        if (c < 0) {
            break;
        }
    }

    printf("Final values are: a=%d, b=%d, c=%d, sum=%d\n", a, b, c, sum);

    // Check if a certain condition holds after the execution
    __VERIFIER_assert(a < (MAX_COUNTER * 10) && sum >= 0);

    return 0;
}