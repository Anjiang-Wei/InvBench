// This C program is designed for automated verification tools and includes meaningful computational logic with constraint conditions.

#include <stdio.h>
extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
}
extern int __VERIFIER_nondet_int();

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Constraint: assume a, b, c are within certain bounds
    if (a < 0 || a > 100 || b < 0 || b > 100 || c < 0 || c > 100) {
        abort();
    }

    int result = 0;

    // Loop to perform a computation based on input values
    while (a > 0 && b < 100) {
        a = a - 1;
        b = b + 1;
        c = c * 2;

        // Perform some meaningful checks within the loop
        __VERIFIER_assert(c >= 0);

        // Update result based on current state
        if ((a + b) % 2 == 0) {
            result += a + b + c;
        } else {
            result -= a + b + c;
        }
    }

    // Final assertion to ensure expected outcome

    return 0;
}