#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int m, n, sum = 0, prod = 1;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m > 0 && m <= 5);
    assume_abort_if_not(n > 0 && n <= 5);

    int i = 0;
    while (i < m) {
        int j = 0;
        while (j < n) {
            sum += i + j;
            prod *= i + j + 1;

            j++;
        }
        i++;
    }

    __VERIFIER_assert(sum >= 0);
}