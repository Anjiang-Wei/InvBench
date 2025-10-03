#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
}

int sum_of_even_numbers(int n) {
    int sum = 0;
    int i = 0;

    while (i <= n) {
        if (i % 2 == 0) {
            sum += i;
        }
        i++;
    }
    return sum;
}

int main() {
    int n = __VERIFIER_nondet_int();
    int calculated_sum, expected_sum;

    // Assume n is a small positive integer
    if (n < 0 || n > 10) {
        return 0;
    }

    calculated_sum = sum_of_even_numbers(n);

    // Calculate expected sum using the formula for sum of first 'm' even numbers: m * (m + 1)
    int m = n / 2;
    expected_sum = m * (m + 1);

    __VERIFIER_assert(calculated_sum == expected_sum);

    return 0;
}