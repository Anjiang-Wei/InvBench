#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int m = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    if (!(a > 0 && b > 0 && m > 0 && n > 0)) {
        return 0;
    }

    // Initialize sum
    int sum_a = 0, sum_b = 0;
    int counter_a = 0, counter_b = 0;

    // Process 'a' times
    while (counter_a < a) {
        sum_a += n;
        counter_a++;
    }

    // Process 'b' times
    while (counter_b < b) {
        sum_b += m;
        counter_b++;
    }

    // Suppose our constraint is that a*n = b*m
    int expected_sum = a * n;
    if (expected_sum == (b * m)) {
        __VERIFIER_assert(sum_b == expected_sum);
    }

    return 0;
}