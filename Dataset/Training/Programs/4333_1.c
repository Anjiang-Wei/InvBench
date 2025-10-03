#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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

#define SIZE 10000000

int main() {
    int n = __VERIFIER_nondet_int();

    // Assuming n is within a reasonable range to avoid excessive running times
    if (n <= 0 || n > SIZE) {
        return 0;
    }

    long long fib_prev = 1;
    long long fib_curr = 1;
    long long fib_next;
    int i = 2; // Starting from the 3rd Fibonacci number

    // Computation of Fibonacci sequence up to the nth number
    while (i < n) {
        fib_next = fib_prev + fib_curr;

        // Simulate a failure if the Fibonacci value exceeds some fix point (e.g. overflow condition)
        if (fib_next < fib_curr) {
        ERROR : {
            reach_error();
            abort();
        }
        }

        fib_prev = fib_curr;
        fib_curr = fib_next;
        i++;
    }

    // Condition based on Fibonacci properties to check using runtime verification tools
    __VERIFIER_assert(fib_curr >= fib_prev);

    printf("Fibonacci(%d) = %lld\n", n, fib_curr);

    return 0;
}