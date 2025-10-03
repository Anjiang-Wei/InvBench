#include <stdio.h>
#include <stdlib.h>

/* The program computes the Collatz sequence for a given number
   and checks whether it ends at 1 within 1000 steps */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "collatz.c", 8, "reach_error"); }
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

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    int steps = 0;

    while (n != 1 && steps < 1000) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }

    __VERIFIER_assert(n == 1 || steps == 1000);

    printf("Collatz sequence terminated in %d steps.\n", steps);

    return 0;
}