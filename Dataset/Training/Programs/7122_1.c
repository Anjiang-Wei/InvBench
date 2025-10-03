#include <assert.h>
void reach_error() { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int number = __VERIFIER_nondet_int();
    int sum = 0;
    int i;

    if (!(number >= 1 && number <= 10)) {
        return 0;
    }

    // Calculate the sum of numbers from 1 to `number`
    for (i = 1; i <= number; i++) {
        sum += i;
    }

    // Check that the sum is the expected value
    int expected_sum = (number * (number + 1)) / 2; // Formula for sum of first n numbers
    __VERIFIER_assert(sum == expected_sum);

    return 0;
}