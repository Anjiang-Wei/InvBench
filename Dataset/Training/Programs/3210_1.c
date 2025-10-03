#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int x = __VERIFIER_nondet_int();

    // Initial constraints to avoid trivial cases
    if (!(a >= 1 && a <= 50)) {
        return 0;
    }
    if (!(b >= 1 && b <= 50)) {
        return 0;
    }
    if (!(x >= 1 && x <= 50)) {
        return 0;
    }

    int sum = 0;
    while (x > 0) {
        if ((x % 2) == 0) {
            // if x is even, increment sum by a
            sum += a;
        } else {
            // if x is odd, increment sum by b
            sum += b;
        }
        x--;
    }

    // Verify that the computed sum is greater than or equal to the minimum possible sum
    __VERIFIER_assert(sum >= b);

    // Print for visualization (Optional)
    printf("Sum: %d\n", sum);

    return 0;
}