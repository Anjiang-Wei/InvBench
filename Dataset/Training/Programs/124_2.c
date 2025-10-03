#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
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
}

int main() {
    int m;
    long long sum = 0, odd_sum = 0;

    m = __VERIFIER_nondet_int();
    if (m < 1 || m > 100) {
        return 1;
    }

    for (int i = 1; i <= m; i++) {
        sum += i;
        if (i % 2 == 1) {
            odd_sum += i;
        }
    }

    // Constraint conditions
    __VERIFIER_assert(odd_sum <= sum);

    printf("Sum up to %d is %lld\n", m, sum);
    printf("Sum of odd numbers up to %d is %lld\n", m, odd_sum);

    return 0;
}