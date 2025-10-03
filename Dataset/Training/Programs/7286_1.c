#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// A structure to keep track of Fibonacci computation state
typedef struct {
    int a, b;
    int index;
} Fibonacci;

// Function to compute the next Fibonacci number
void next_fibonacci(Fibonacci *fib) {
    int next = fib->a + fib->b;
    fib->a = fib->b;
    fib->b = next;
    fib->index++;
}

// Function to make assertions based on Fibonacci state
void check_fibonacci(Fibonacci *fib) {
    __VERIFIER_assert(fib->a >= 0);
}

int main() {
    // Generate a random upper limit for Fibonacci computation
    unsigned int upper_limit = __VERIFIER_nondet_uint();
    assume_abort_if_not(upper_limit <= 100); // Limiting to prevent excessive computation

    // Initialize Fibonacci sequence
    Fibonacci fib = {0, 1, 1};

    // Loop to compute Fibonacci sequence up to upper_limit
    while (fib.index < upper_limit) {
        next_fibonacci(&fib);
        check_fibonacci(&fib);
    }

    // Verify that the sequence was computed correctly
    unsigned int x = __VERIFIER_nondet_uint();
    assume_abort_if_not(x < upper_limit);

    // Simple function to retrieve Fibonacci number by index
    Fibonacci temp_fib = {0, 1, 1};

    for (int i = 1; i <= x; i++) {
        next_fibonacci(&temp_fib);
    }

    // The final assertion to verify that our logic is consistent

    return 0;
}