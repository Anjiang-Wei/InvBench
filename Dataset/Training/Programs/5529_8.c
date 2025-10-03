#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Compute the factorial of a non-negative integer
int main() {
    int n = __VERIFIER_nondet_int();
    int result = 1;
    int i;

    // Assume the input is within a reasonable range
    assume_abort_if_not(n >= 0 && n <= 7);

    i = 1;

    while (i <= n) {
        result = result * i;
        i++;
    }

    // Verify the result of factorial for known input
    switch (n) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        __VERIFIER_assert(result == 5040);
        break;
    default:
        reach_error();
        break;
    }

    return 0;
}