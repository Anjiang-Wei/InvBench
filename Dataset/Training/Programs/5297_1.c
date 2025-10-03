#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define MAX_ITEMS 20

int main() {
    int array[MAX_ITEMS];
    int i, n = __VERIFIER_nondet_int();

    if (n < 1 || n > MAX_ITEMS) {
        return 0; // Precondition to ensure valid inputs
    }

    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int positive_count = 0, negative_count = 0;
    for (i = 0; i < n; i++) {
        if (array[i] > 0) {
            positive_count++;
        } else if (array[i] < 0) {
            negative_count++;
        }
    }

    int total = positive_count + negative_count;

    // We assert that the number of elements with a sign (positive or negative) is less than or equal to the total number of elements
    __VERIFIER_assert(total <= n);

    // Print the count of positive and negative numbers for observation
    printf("Positive count: %d, Negative count: %d\n", positive_count, negative_count);

    return 0;
}