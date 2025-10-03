#include <stdio.h>
#include <stdlib.h>

// Function declarations
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);

// Main function
int main() {
    int M = __VERIFIER_nondet_int();
    assume_abort_if_not(M >= 0 && M <= 1000000);

    long long sum_even = 0;
    long long sum_odd = 0;
    int i = 0;

    while (i < M) {
        if (i % 2 == 0) {
            sum_even += i * i;
        } else {
            sum_odd += i * i * i;
        }
        i++;
    }

    __VERIFIER_assert(sum_even % 2 == 0);

    return 0;
}