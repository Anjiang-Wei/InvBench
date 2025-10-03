#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_series.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int();
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main(void) {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 100);

    int series_sum = 0;
    int constant_increment = 5;
    int iterations = 0;

    while (n > 0) {
        if (n % 2 == 0) {
            series_sum += constant_increment;
        } else {
            series_sum += n;
        }

        __VERIFIER_assert(series_sum >= 0);

        if (iterations > 100) {
            // Prevent infinite loops in case something goes wrong
            break;
        }

        n--;
        iterations++;
    }

    printf("Calculated series sum: %d\n", series_sum);

    return 0;
}