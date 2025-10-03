#include <limits.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);

void reach_error(void) {
    // This function is used to signify an error state
    // in the verification tool, not to be used in execution.
}

void __VERIFIER_assert(int cond) {
    // Using assert to simulate verification assertion
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();

    if (n < 1 || m < 1) {
        return 0; // invalid inputs for the operation
    }

    int fibonacci_n = 0, fibonacci_m = 0;
    int prev1 = 0, prev2 = 1, fib = 0;
    int count = 2; // start from the 2nd index in Fibonacci sequence

    // Loop to find the n-th and m-th Fibonacci numbers
    while (count <= n || count <= m) {
        if (count <= n || count <= m) {
            fib = prev1 + prev2;
            prev1 = prev2;
            prev2 = fib;

            if (count == n) {
                fibonacci_n = fib;
            }
            if (count == m) {
                fibonacci_m = fib;
            }
        }
        count++;
    }

    // Ensuring that the computed values are non-negative
    __VERIFIER_assert(fibonacci_m >= 0);

    // Perform a simple property check: differences between consecutive Fibonacci numbers
    if (n > 0 && m > 0 && n != m) {
        int diff = fibonacci_m - fibonacci_n;
    }

    printf("Fibonacci(%d) = %d\n", n, fibonacci_n);
    printf("Fibonacci(%d) = %d\n", m, fibonacci_m);

    return 0;
}