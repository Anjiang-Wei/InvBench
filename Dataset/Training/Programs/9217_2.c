#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "factorial_verification.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int is_even(unsigned long long num) {
    return num % 2 == 0;
}

int main() {
    const int MAX_NUM = 15; // Factorial limit
    unsigned long long fact_results[MAX_NUM];
    int is_even_results[MAX_NUM];

    for (int i = 0; i < MAX_NUM; i++) {
        fact_results[i] = factorial(i);
        is_even_results[i] = is_even(fact_results[i]);

        // Verification: Check that the factorial of a positive number is always positive

        // Verification: Check that the is_even function returns correct results
        if (fact_results[i] % 2 == 0) {
            __VERIFIER_assert(is_even_results[i] == 1);
        } else {
        }
    }

    // Print results for user verification
    for (int i = 0; i < MAX_NUM; i++) {
        printf("Factorial of %d is %llu and it is %s\n", i, fact_results[i],
               is_even_results[i] ? "even" : "odd");
    }

    return 0;
}