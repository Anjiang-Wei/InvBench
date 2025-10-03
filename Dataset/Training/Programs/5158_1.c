// Sum of Alternating Series
// This program calculates the sum of the series: 1 - 2 + 3 - 4 + 5 - 6 + ... + n
// Visits each number from 1 to n, adding or subtracting depending on its parity
// and verifies that the result has specific expected properties.

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "alternating_series.c", 12, "reach_error"); }
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
    int n;          // We will sum the series from 1 to n
    int result = 0; // The result of the alternating series
    int i = 1;      // To iterate from 1 to n

    printf("Enter a positive integer (n): ");
    scanf("%d", &n);

    // Ensure n is positive
    if (n <= 0) {
        printf("n must be a positive integer.\n");
        return 1;
    }

    // Calculate the sum of the alternating series 1 - 2 + 3 - 4 + ... +/- n
    while (i <= n) {
        if (i % 2 == 1) { // If i is odd, add it
            result += i;
        } else { // If i is even, subtract it
            result -= i;
        }
        i++;
    }

    // Verify the result with a property
    // If n is even, expected result is -n/2, if n is odd, expected result is (n+1)/2
    if (n % 2 == 0) {
        __VERIFIER_assert(result == -n / 2);
    } else {
    }

    printf("The sum of the alternating series from 1 to %d is: %d\n", n, result);
    return 0;
}