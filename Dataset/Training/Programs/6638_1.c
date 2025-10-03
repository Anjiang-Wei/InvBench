#include <stdio.h>
#include <stdlib.h>

// Simulate nondeterministic integer
int __VERIFIER_nondet_int() {
    return rand() % 100;
}

// Simulate nondeterministic boolean
_Bool __VERIFIER_nondet_bool() {
    return rand() % 2;
}

// Simulate error condition
void reach_error(void) {
    printf("Error reached!\n");
    abort();
}

// A custom assert function that calls reach_error on failure
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assume some precondition
    if (!(a > 0 && b > 0)) {
        return 0;
    }

    int product = a * b;
    int c = 0;
    int result = 0;

    // Loop that "simulates" multiplication by repeated addition
    while (c < b) {
        result += a;
        c++;

        // A condition that must remain true
        __VERIFIER_assert(result == a * c);
    }

    // Postcondition check

    // Print success message
    printf("Computation successful: %d * %d = %d\n", a, b, result);

    return 0;
}