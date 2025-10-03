#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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
}

int main() {
    int limit, sum = 0, n = 0;
    limit = __VERIFIER_nondet_int();
    assume_abort_if_not(limit > 0 && limit < 1000);

    while (1) {
        __VERIFIER_assert(sum == n * (n - 1) / 2);

        if (!(n < limit)) {
            break;
        }

        sum += n;
        n++;
    }

    printf("Sum of first %d natural numbers is %d.\n", n - 1, sum);
    return 0;
}