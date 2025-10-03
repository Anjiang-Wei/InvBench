#include <stdio.h>

// external declarations for verification functions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

// function to assume conditions that abort if not met
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// simple assert function that calls reach_error
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

// main function with meaningful computational logic and a loop
int main() {
    int n, a, b, sum;
    n = __VERIFIER_nondet_int(); // nondeterministic input

    assume_abort_if_not(n >= 0); // assume n is non-negative

    // initialize variables
    a = 0;
    b = 1;
    sum = 0;

    // loop to calculate the sum of the first 'n' Fibonacci numbers
    for (int i = 0; i < n; i++) {
        int next = a + b;
        sum += a;
        a = b;
        b = next;
    }

    // final assertion to verify the sum is non-negative
    __VERIFIER_assert(sum >= 0);

    printf("Sum of first %d Fibonacci numbers is %d\n", n, sum);
    return 0;
}