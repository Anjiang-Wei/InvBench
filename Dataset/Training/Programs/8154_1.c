#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }
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

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        return 0;
    }

    int sum_even = 0;
    int sum_odd = 0;
    int num_odd = 0;
    int num_even = 0;

    for (int i = 1; i <= N; i++) {
        if (i % 2 == 0) {
            sum_even += i;
            num_even += 1;
        } else {
            sum_odd += i;
            num_odd += 1;
        }
    }

    // A simple mathematical condition to check
    if (N % 2 == 0) {
        __VERIFIER_assert(num_odd == num_even);
    } else {
    }

    // Print results (to ensure correctness when compiled normally)
    printf("Sum of even numbers: %d\n", sum_even);
    printf("Sum of odd numbers: %d\n", sum_odd);
    printf("Even count: %d, Odd count: %d\n", num_even, num_odd);

    return 0;
}