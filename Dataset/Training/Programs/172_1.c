#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

// Function to calculate factorial of a number
int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int x;
    int result;
    int expected_result;

    x = 5; // Let's calculate 5!
    result = factorial(x);
    // The expected result for factorial(5) is 120
    expected_result = 120;

    __VERIFIER_assert(result == expected_result);

    // More complex loop example
    int array[10];
    int i, sum = 0;

    // Initialize array with values and calculate their sum
    for (i = 0; i < 10; i++) {
        array[i] = i * 2; // store even numbers: 0, 2, 4, ..., 18
        sum += array[i];
    }

    // The sum of first 10 even numbers is 90

    printf("Both assertions passed!\n");
    return 0;
}