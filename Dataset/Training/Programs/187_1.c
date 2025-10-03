#include <assert.h>
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

// Function to find the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int x = 270;
    int y = 192;

    // Calculate GCD of x and y
    int result = gcd(x, y);

    // The GCD of these numbers is known to be 6
    __VERIFIER_assert(result == 6);

    return 0;
}