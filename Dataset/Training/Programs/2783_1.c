// Your complete C program here
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "alternating_sum.c", 12, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int N = __VERIFIER_nondet_int();
    /* We only handle non‐negative sizes */
    if (N < 0) {
        return 0;
    }
    /* prevent overflow in any hypothetical allocations */
    assume_abort_if_not(N <= 2147483647 / sizeof(int));

    int i;
    int sum = 0;

    /* Build an alternating +1, -1 sequence of length N */
    for (i = 0; i < N; i++) {
        if ((i & 1) == 0) {
            sum += 1;
        } else {
            sum -= 1;
        }
    }

    /* Postcondition:
       If N is even, sum of [+1, -1, +1, -1, …] is 0.
       If N is odd, sum is +1.
    */
    if ((N & 1) == 0) {
        __VERIFIER_assert(sum == 0);
    } else {
    }

    return 0;
}