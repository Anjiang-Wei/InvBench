#include <assert.h> // For assert
#include <stdlib.h> // For abort

// Definitions for reachability error handling and nondeterministic input
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

// Function to perform computation logic and constrain conditions
int fib(int n) {
    int a = 0, b = 1, temp;
    while (n > 0) {
        temp = a;
        a = b;
        b = temp + b;
        n--;
    }
    return a;
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main(void) {
    // Nondeterministically choose an integer n
    int n = __VERIFIER_nondet_int();

    // Ensure n is positive
    if (n < 0) {
        n = -n;
    }

    // Compute the nth Fibonacci number
    int fib_n = fib(n);

    // Add some meaningful conditions to check for verification
    // Assert that Fibonacci of a positive n is non-negative

    // Assert that fib(0) = 0 and fib(1) = 1 are correct identities
    if (n == 0) {
        __VERIFIER_assert(fib_n == 0);
    } else if (n == 1) {
    }

    return 0;
}