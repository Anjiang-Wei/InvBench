#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int calculate_sum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    int n = 100;                          // Calculate the sum of the first 100 natural numbers
    int expected_sum = (n * (n + 1)) / 2; // Formula for the sum of first n natural numbers

    int computed_sum = calculate_sum(n);

    // Verification condition to ensure computed sum matches the expected sum
    __VERIFIER_assert(computed_sum == expected_sum);

    printf("Sum of first %d natural numbers is %d\n", n, computed_sum);

    return 0;
}