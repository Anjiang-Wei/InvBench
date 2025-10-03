#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void reach_error() {
    printf("Error reached\n");
    abort();
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int limit = 100;
    int sum = 0;
    int increment = 1;

    // Ensure `n` is constrained within a reasonable range
    if (n < 1 || n > 50) {
        printf("Invalid input range\n");
        return -1;
    }

    while (increment <= n) {
        sum = sum + increment;
        increment = increment + 1;

        // Verifying that the sum at each point is consistent with sum of first `increment-1` natural numbers
        __VERIFIER_assert(sum == (increment - 1) * increment / 2);
    }

    // Final assert to verify the correctness after loop

    if (sum > limit) {
        printf("Sum exceeded limit: %d\n", sum);
    } else {
        printf("Valid sum: %d\n", sum);
    }

    return 0;
}