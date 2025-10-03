#include <assert.h>
extern void abort(void);
extern int __VERIFIER_nondet_int(void);

// Function to trigger a verification error
void reach_error() { assert(0); }

// Custom assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Fibonacci sequence computation
int main() {
    int n = __VERIFIER_nondet_int();

    // Assume n is in a reasonable range for Fibonacci computation
    if (n < 0 || n > 30) {
        return 0;
    }

    int fib1 = 0;
    int fib2 = 1;
    int temp;
    int counter = 2;

    while (counter <= n) {
        temp = fib1 + fib2;
        fib1 = fib2;
        fib2 = temp;
        counter++;
    }

    // Postcondition: fib2 holds the nth Fibonacci number
    __VERIFIER_assert(fib2 >= fib1);

    return 0;
}