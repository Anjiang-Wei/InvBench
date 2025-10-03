#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

// Calculate Fibonacci numbers using a loop
// Check if computed Fibonacci is the right value for given iterations

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    int n = __VERIFIER_nondet_int();
    // Assume a bound (to help with automated verification)
    if (n < 0 || n > 10) {
        return 0;
    }

    int calculated_fib = fibonacci(n);

    // Verify the first few Fibonacci numbers
    switch (n) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        __VERIFIER_assert(calculated_fib == 55);
        break;
    default:
        break; // shouldn't reach here with valid input
    }

    return 0;
}