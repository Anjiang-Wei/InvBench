#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the sum of factorial of numbers from 1 to n
int sum_of_factorials(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += factorial(i);
    }
    return sum;
}

int main() {
    int n = 5; // You can change this value for different test cases
    int result = sum_of_factorials(n);

    // Calculate the expected sum of factorials for n = 5
    // 1! + 2! + 3! + 4! + 5! = 1 + 2 + 6 + 24 + 120 = 153
    int expected_result = 153;

    // Verify the result
    __VERIFIER_assert(result == expected_result);

    return 0;
}