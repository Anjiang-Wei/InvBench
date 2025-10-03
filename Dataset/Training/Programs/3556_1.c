#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

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

extern _Bool __VERIFIER_nondet_bool();
extern int __VERIFIER_nondet_int();

int main() {
    int a = __VERIFIER_nondet_int();
    int b = 0;
    int sum = 0;

    // Initialize a safe boundary for demonstrative purpose in a verification scenario
    if (a < 0 || a > 100) {
        a = 50; // Assume a safe range for the demonstration
    }

    while (b <= a) {
        sum += b;
        b++;
    }

    // Final assertion checks
    __VERIFIER_assert(b == a + 1);

    printf("Sum of numbers from 0 to %d is: %d\n", a, sum);
    return 0;
}