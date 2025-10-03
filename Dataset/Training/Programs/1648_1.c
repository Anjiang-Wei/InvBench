#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Fibonacci Sequence Checker
Fibonacci numbers are characterized by the fact that every number after the first two is the sum of the two preceding ones.
Given a number n, verify if it appears in the Fibonacci sequence.
*/
int is_fibonacci(int n) {
    if (n < 0) {
        return 0; // No negative numbers in Fibonacci
    }

    int a = 0, b = 1, temp;
    while (a < n) {
        temp = a;
        a = b;
        b = temp + b;
    }

    // Return true if the number is found in the sequence
    return a == n;
}

int main() {
    int n = __VERIFIER_nondet_int();

    // We assume n to be in a reasonable checked range for a simple Fibonacci verification
    if (n > 10000 || n < 0) {
        return 0;
    }

    int result = is_fibonacci(n);

    // If the function identifies n in the Fibonacci series, check correctness
    if (result) {
        // Check if n is correctly identified using properties of Fibonacci
        int a = 0, b = 1;
        while (a < n) {
            int temp = a;
            a = b;
            b = temp + b;
        }
        __VERIFIER_assert(a == n);
    }

    return 0;
}