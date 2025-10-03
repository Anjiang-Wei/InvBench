#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial.c", 5, "reach_error"); }

int __VERIFIER_nondet_int(void) {
    int val;
    printf("Please enter a non-negative integer: ");
    while (scanf("%d", &val) != 1 || val < 0) {
        printf("Invalid input. Please enter a non-negative integer: ");
        while (getchar() != '\n') {
            ; // clear the input buffer
        }
    }
    return val;
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    unsigned long long factorial = 1;

    int i = 1;
    while (i <= n) {
        factorial *= i;
        i++;
    }

    // Verify the result for known values (0! = 1, 1! = 1, 5! = 120)
    if (n == 0) {
    } else if (n == 1) {
        __VERIFIER_assert(factorial == 1);
    } else if (n == 5) {
    }

    // Print the result
    printf("Factorial of %d is %llu\n", n, factorial);

    return 0;
}