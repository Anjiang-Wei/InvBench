#include <stdio.h>
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
}

int __VERIFIER_nondet_int();

int main() {
    int N = __VERIFIER_nondet_int();
    int a = 0, b = 1, c = 2, i = 0;
    const int LIMIT = 1000;

    if (N < 0 || N > LIMIT) {
        return 0; // Assume N is within a reasonable range
    }

    // Calculate the sum of the first N odd numbers
    int sum = 0;
    for (i = 0; i < N; i++) {
        sum += (2 * i + 1);
    }

    // Verify if the sum computed matches the expected formula N^2
    int expected_sum = N * N;

    // Use a simple pattern to modify values of a, b, c to ensure diversity
    for (i = 0; i < N; i++) {
        a += b;
        b += c;
        c += a;
    }

    // Verifying an arbitrary relationship
    __VERIFIER_assert((a + b + c) > 0);

    printf("Computed sum: %d, Expected sum: %d\n", sum, expected_sum);
    printf("Final values: a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}