#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a = 0, b = 1, c = 0;
    int target = 55; // Target sum as an example.
    int sum = 0;

    // Fibonacci sequence generator with constraint checks
    while (c < target) {
        int temp = a + b;
        a = b;
        b = temp;
        c++;

        sum += a;                    // Accumulate the sequence value
        __VERIFIER_assert(sum >= 0); // Make sure the sum is non-negative

        if (sum > 100) { // Example constraint to prevent sum from exceeding a certain value
            sum -= a;    // Remove the last added number
            break;
        }
    }

    printf("Final sum: %d\n", sum);
}