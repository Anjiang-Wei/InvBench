#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int counter = 0;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void analyze_factorial_sum(int limit) {
    int sum = 0;
    int i = 1;

    while (counter++ < 100 && i <= limit) {
        sum += factorial(i);
        i++;

        // Check for a condition where sum is always positive within the loop
        __VERIFIER_assert(sum >= 0);
    }
}

int main() {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n < 10); // Ensure a plausible limit to factorial calculation

    analyze_factorial_sum(n);

    return 0;
}