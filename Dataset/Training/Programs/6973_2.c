#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// A program to verify summation and difference logic
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume valid input ranges
    assume_abort_if_not(n > 0 && n <= 10);
    assume_abort_if_not(a >= 0 && b >= 0 && a <= 100 && b <= 100);

    int sum = a + b;
    int diff = abs(a - b);

    while (n > 0) {
        int choice = __VERIFIER_nondet_int();
        assume_abort_if_not(choice >= 0 && choice <= 2);

        if (choice == 0 && sum >= diff) {
            sum -= diff;
        } else if (choice == 1) {
            sum += diff;
        } else if (choice == 2) {
            diff += (sum % 10);
            if (diff > 100) {
                diff = 100; // Cap at 100
            }
        }
        n--;
    }

    // Ensure that sum and diff are consistent under the modified operations
    // Conclude with the range constraint check
    __VERIFIER_assert(diff >= 0 && diff <= 100);

    printf("Sum: %d\n", sum);
    printf("Diff: %d\n", diff);

    return 0;
}