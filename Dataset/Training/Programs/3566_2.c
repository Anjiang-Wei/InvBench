// Program to compute Fibonacci numbers and verify the sequence properties

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "fibonacci.c", 5, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}

int main() {
    int prev = 0, curr = 1, next;
    int target = 10; // Fibonacci series target number
    int count = 0;

    assume_abort_if_not(target >= 0);

    while (count < target) {
        next = prev + curr;

        // Verify that each Fibonacci number is the sum of the two preceding numbers

        prev = curr;
        curr = next;
        count++;
    }

    // Check if the target Fibonacci number is greater than or equal to the starting value
    // which is a property for Fibonacci numbers after the first few elements.
    __VERIFIER_assert(curr >= 0);

    printf("The %d-th Fibonacci number is %d\n", target, curr);
    return 0;
}