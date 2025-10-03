#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    int sum_odd = 0;
    int sum_even = 0;
    int total_sum = 0;
    int counter = 0;

    for (int i = 1; i <= 2 * n; i++) {
        total_sum += i;
        if (i % 2 == 0) {
            sum_even += i;
        } else {
            sum_odd += i;
        }
        counter++;
    }

    // We assert that the total sum is indeed the sum of sum_odd and sum_even
    __VERIFIER_assert(total_sum == (sum_odd + sum_even));

    // Another loop to check that the number of even plus odd numbers is total_sum
    int computed_sum = 0;
    for (int j = 0; j < counter; j++) {
        computed_sum++;
    }

    return 0;
}