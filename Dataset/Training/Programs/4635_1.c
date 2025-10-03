#include <assert.h>
#include <stdio.h>

extern void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New program example that uses Pythagorean triples */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();
    int a, b, c;

    // Assume m > n > 0 to form a primitive Pythagorean triple
    if (!(m > n && n > 0 && gcd(m, n) == 1 && (m - n) % 2 == 1)) {
        return 0;
    }

    // Generate a Pythagorean triple
    a = (m * m) - (n * n);
    b = 2 * m * n;
    c = (m * m) + (n * n);

    // Ensure that the Pythagorean theorem holds
    __VERIFIER_assert(a * a + b * b == c * c);

    // Look for even number of iterations for some logical condition
    int count = 100;
    while (count > 0) {
        _Bool condition = __VERIFIER_nondet_bool();
        if (condition) {
            a += 2;
        } else {
            b += 2;
        }
        // Ensure the computation remains valid in some way
        count--;
    }

    printf("Final values: a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}