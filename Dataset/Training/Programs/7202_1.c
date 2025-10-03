/*
 * Example Program 4:
 * This program calculates the sum of an arithmetic series and checks its properties.
 * The series is defined as S = 1 + 2 + 3 + ... + n
 */

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int n;
    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n must be positive.\n");
        return 1;
    }

    int sum = 0;
    int i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }

    int expected_sum = n * (n + 1) / 2;

    __VERIFIER_assert(sum == expected_sum);

    printf("Computed sum: %d\n", sum);
    printf("Expected sum using formula: %d\n", expected_sum);

    return 0;
}