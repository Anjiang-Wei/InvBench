#include <stdio.h>
#include <stdlib.h>

// Function to simulate a nondeterministic integer input
extern int __VERIFIER_nondet_int(void);

// Exit the program if a condition is not met
void reach_error() {
    printf("Error: Reached an unexpected state.\n");
    exit(1);
}

// A custom assert function to incorporate reach_error
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

// A function that calculates the Fibonacci sequence iteratively
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0, b = 1, c, i;
    for (i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    // Get a nondeterministic integer, representing the Fibonacci position
    int n = __VERIFIER_nondet_int();
    if (n < 0 || n > 20) { // Restrict `n` for practical reasons in this demo
        return 0;
    }

    // Calculate the Fibonacci number at position `n`
    int fib_n = fibonacci(n);

    // Assuming the first few Fibonacci numbers known
    int known_fib[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};

    // Verify that calculated Fibonacci value matches the expected number
    if (n >= 0 && n <= 20) {
        __VERIFIER_assert(fib_n == known_fib[n]);
    }

    printf("Fibonacci number at position %d is %d\n", n, fib_n);
    return 0;
}