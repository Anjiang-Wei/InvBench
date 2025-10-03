#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Function to calculate factorial recursively
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// A function to compute the n-th Fibonacci number iteratively
int fibonacci(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

// Function to compute a series sum
int series_sum(int n) {
    int sum = 0, i;
    for (i = 0; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z;

    assume_abort_if_not(x > 0 && y > 0);

    printf("Factorial of %d is %d\n", x, factorial(x));
    printf("Fibonacci of %d is %d\n", y, fibonacci(y));

    // Loop with assertions and nondeterministic choices
    int count = 0;
    while (count < 10) {
        if (__VERIFIER_nondet_bool()) {
            z = series_sum(count);
            printf("Series sum up to %d is %d\n", count, z);
        }
        count++;
    }

    // Final check to ensure program logic
    __VERIFIER_assert(y > 0);

    return 0;
}