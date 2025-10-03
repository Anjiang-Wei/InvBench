#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern unsigned int __VERIFIER_nondet_uint(void);

void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();
    unsigned int sum = 0;

    // Precondition: a must be less than b
    if (!(a < b)) {
        return 0;
    }

    unsigned int diff = b - a; // Calculate the initial difference

    while (a < b) {
        sum += a;
        a++;

        // Let's add a condition such that the loop ends if certain relations
        // between 'sum' and 'diff' hold true, but it might never be hit.
        if (sum >= diff * (b - a) / 2) {
            break;
        }
    }

    // Postcondition: Ensure that the loop condition is correctly captured and handled
    __VERIFIER_assert(sum >= diff * (b - a) / 2 || a == b);

    printf("Sum: %u\n", sum);

    return 0;
}