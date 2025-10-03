#include <stdio.h>
#include <stdlib.h>

// Function declarations for verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int max_sum = 1000;
    int sum1 = 0, sum2 = 0;
    int i = 0, j = 0;

    int n1 = __VERIFIER_nondet_int();
    assume_abort_if_not(n1 >= 0);

    int n2 = __VERIFIER_nondet_int();
    assume_abort_if_not(n2 >= 0);

    while (1) {
        if (i < n1) {
            sum1 += 2; // Increment sum1 by 2 for each iteration
            i++;
        } else if (i == n1 && j < n2) {
            sum2 += 3; // Increment sum2 by 3 once sum1 is filled
            j++;
        } else {
            break;
        }

        // Prevent overflow or an unbounded loop
        assume_abort_if_not(sum1 + sum2 <= max_sum);
    }

    // Validate total sum
    int total_sum = sum1 + sum2;
    printf("Sum1: %d, Sum2: %d, Total Sum: %d\n", sum1, sum2, total_sum);
    __VERIFIER_assert(total_sum <= max_sum);

    return 0;
}