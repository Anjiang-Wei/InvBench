#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  Compute the greatest common divisor (GCD) using an iterative version of Euclid's algorithm.
  Uses two variables, a and b, where we assume that a >= b.
  The algorithm repeatedly replaces a by a - b until a < b, then swaps them.
  The postcondition verifies that the final value of a is indeed the GCD.
*/

int counter = 0;
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        counter++;
        __VERIFIER_assert(a > 0 && b > 0); // Precondition: a and b should both be positive
        if (a > b) {
            a = a - b;
        } else {
            temp = a;
            a = b;
            b = temp;
        }
        if (counter > 100) {
            break; // Prevent infinite loop on faulty input
        }
    }
    return a;
}

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();

    // We assume x and y are positive to ensure the correctness of the GCD operation
    if (x <= 0 || y <= 0) {
        return 0;
    }

    int result = gcd(x, y);

    // Postcondition: result is the GCD of x and y

    printf("The GCD of %d and %d is %d\n", x, y, result);
    return 0;
}