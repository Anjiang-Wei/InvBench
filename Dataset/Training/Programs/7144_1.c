#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "fibonacci.c", 7, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int n;
    n = __VERIFIER_nondet_uint();
    assume_abort_if_not(n >= 1 && n <= 20); // Limit `n` to a manageable size

    long long fib1 = 0, fib2 = 1, fib_next = 0;
    long long sum_of_evens = 0;
    unsigned int count = 0;

    while (count < n) {
        fib_next = fib1 + fib2;
        if (fib_next % 2 == 0) {
            sum_of_evens += fib_next;
        }

        fib1 = fib2;
        fib2 = fib_next;
        count++;
    }

    // Check the correctness of the sum of even Fibonacci numbers condition at a given point
    __VERIFIER_assert(sum_of_evens >= 0); // It's a simple property that the sum should always be non-negative

    printf("Sum of even Fibonacci numbers up to term %u: %lld\n", n, sum_of_evens);
    return 0;
}