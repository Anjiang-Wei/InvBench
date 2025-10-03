#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
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

int main() {
    int n, i;
    long long factorial = 1, sum_of_factorials = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 12); // Limit due to integer overflow: 12! is the largest factorial within int bounds.

    // Calculate the factorial of n and sum of all factorials from 1 to n
    for (i = 1; i <= n; i++) {
        factorial *= i;                 // Calculate i!
        sum_of_factorials += factorial; // Add i! to the sum
    }

    // Verify that the sum_of_factorials is correct for the known value when n = 5;
    if (n == 5) {
        __VERIFIER_assert(sum_of_factorials == 153); // 1! + 2! + 3! + 4! + 5! = 153
    }

    printf("Factorial of %d is %lld\n", n, factorial);
    printf("Sum of factorials up to %d is %lld\n", n, sum_of_factorials);

    return 0;
}