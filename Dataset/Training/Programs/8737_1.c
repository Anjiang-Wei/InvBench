#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern void abort(void);
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

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000000);

    long long sumOdd = 0;
    long long sumEven = 0;

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sumEven += i;
        } else {
            sumOdd += i;
        }
    }

    // Check if the absolute difference between sum of odd and even numbers
    // is less than or equal to N.
    __VERIFIER_assert(abs(sumOdd - sumEven) <= N);

    printf("Sum of odd numbers: %lld\n", sumOdd);
    printf("Sum of even numbers: %lld\n", sumEven);
    printf("Absolute difference: %lld\n", llabs(sumOdd - sumEven));

    return 0;
}