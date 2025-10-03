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

extern int __VERIFIER_nondet_int(void);

// New C program based on the observed patterns and structures

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition based on some mathematical relationship
    if (!(a >= 0 && b >= 0 && a == 5 * b)) {
        return 0;
    }

    int sum = 0;
    int count = 0;

    // Loop: Summation logic
    while (b > 0) {
        sum += 5;
        b--;
        count++;
    }

    // Postcondition we expect to hold after the loop
    __VERIFIER_assert(sum == a);

    printf("Completed: sum = %d, count = %d\n", sum, count);

    return 0;
}