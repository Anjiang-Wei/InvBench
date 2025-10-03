#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int i = 0;
    int n = 15; // A determinate example; change as needed for nondeterminism
    int a = 0;
    int b = 1;

    if (n < 0) {
        return 0; // Early exit condition for non-positive n
    }

    // Calculate the n-th Fibonacci number using iterative method
    while (i < n) {
        int temp = a;
        a = b;
        b = temp + b;
        i++;
    }

    // Verify the result using a postcondition
    // This checks if the final `a` is a positive number (since it should be for n >= 1)
    __VERIFIER_assert(a > 0);

    printf("Fibonacci number %d is %d\n", n, a);

    return 0;
}