#include <assert.h>
#include <stdio.h>

// Function prototypes
extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int gcd(int a, int b) {
    while (b != 0) {
        int old_b = b;
        b = a % b;
        a = old_b;
    }
    return a;
}

int main() {
    // Simple GCD computation for two numbers
    int x = 81; // Input can be generated or fixed. Here, we use fixed input.
    int y = 153;

    if (x < 0 || y < 0) {
        printf("Inputs must be non-negative.\n");
        return 1;
    }

    int result = gcd(x, y);

    __VERIFIER_assert(result >= 0);

    // If x and y are both zero, our gcd function should never be called

    // Result should divide both x and y
    if (x != 0) {
    }
    if (y != 0) {
    }

    // Output the result for comprehension
    printf("GCD of %d and %d is %d\n", x, y, result);

    return 0;
}