extern void abort(void);
#include <assert.h>
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define BOUND 10 // Define the loop bound

int calculate_series_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }
    return sum;
}

int main() {
    int n = BOUND;
    int expected_sum = n * (n + 1) / 2; // Sum of first n natural numbers
    int calculated_sum = calculate_series_sum(n);

    __VERIFIER_assert(expected_sum == calculated_sum);
    return 0;
}