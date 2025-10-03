#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

_Bool __VERIFIER_nondet_bool();

int compute_series_sum(int n) {
    int sum = 0;
    int current_number = 1;
    int counter = 0;

    while (counter < n) {
        sum += current_number;
        current_number += 2; // Increment by 2 for the next odd number
        counter++;
    }

    return sum;
}

int main() {
    _Bool is_valid = __VERIFIER_nondet_bool();
    int n = 5; // We intend to sum the first 5 odd numbers
    int result;

    if (is_valid) {
        result = compute_series_sum(n);
    } else {
        result = compute_series_sum(n - 1);
        result += 9; // Directly adding the 5th odd number if skipped
    }

    // With n=5, sum of first 5 odd numbers is 1+3+5+7+9 = 25
    __VERIFIER_assert(result == 25);

    printf("Computed sum is: %d\n", result); // This line is for visualization and can be ignored during verification
    return 0;
}