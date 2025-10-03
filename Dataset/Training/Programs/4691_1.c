#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

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
    int n;
    int sum = 0;
    int expected_sum;
    int c = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    expected_sum = n * (n + 1) / 2; // Expected sum of first n natural numbers

    // Loop to calculate the actual sum
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    // Assert to ensure the calculated sum is correct
    __VERIFIER_assert(sum == expected_sum);

    // Additional loop that modifies sum under certain conditions
    while (c < n) {
        if (c % 2 == 0) {
            sum += c;
        } else {
            sum -= c;
        }
        c++;
    }

    // Final assertion to check a specific property

    return 0;
}