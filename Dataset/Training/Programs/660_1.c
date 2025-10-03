#include <stdio.h>
#include <stdlib.h>

// External functions for verification purposes
extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "newprogram.c", 10, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int W; // Global variable to hold the width of a hypothetical structure

int main() {
    W = __VERIFIER_nondet_int();
    assume_abort_if_not(W > 0);
    assume_abort_if_not(W <= 1000);

    int length = 0;
    int total_area = 0;
    int i = 0;
    const int MAX_LENGTH = 50;

    // Loop to simulate some geometry-based task
    while (length < MAX_LENGTH) {
        int cur_width = (i % 2 == 0) ? W : W / 2;
        int cur_length = W + i;

        // Simulate the computation of an area for a rectangular framework
        int cur_area = cur_width * cur_length;
        total_area += cur_area;

        // Prevent overflow in total_area
        assume_abort_if_not(total_area >= 0);

        length++;
        i++;
    }

    // Post-conditions to be checked after the loop
    __VERIFIER_assert(total_area >= 0);      // Verify non-negativity of total area
    __VERIFIER_assert(length == MAX_LENGTH); // Ensure loop ran the intended number of times

    printf("Total area: %d\n", total_area);
    return 0;
}