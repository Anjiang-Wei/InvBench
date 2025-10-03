#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }
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
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 1;
    }

    long long sum_odd = 0;
    long long sum_even = 0;

    assume_abort_if_not(N <= 1000); // To ensure feasibly small numbers.

    int i;
    for (i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sum_even += i * i;
        } else {
            sum_odd += i * i * i;
        }
    }

    __VERIFIER_assert(sum_odd % 2 == 1 || sum_even % 2 == 0);

    printf("Sum of squares of even numbers: %lld\n", sum_even);
    printf("Sum of cubes of odd numbers: %lld\n", sum_odd);

    return 0;
}