#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "calculate_series.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n, limit, i;
    long long series_sum, current_term, factorial_val;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 20);

    series_sum = 0;
    limit = 5;
    current_term = 1;

    for (i = 0; i < limit; i++) {
        factorial_val = factorial(i);
        current_term = (i % 2 == 0) ? factorial_val : -factorial_val;
        series_sum += current_term;

        __VERIFIER_assert(current_term == (i % 2 == 0 ? factorial(i) : -factorial(i)));

        if (series_sum < -1000 || series_sum > 1000) {
            break;
        }
    }

    printf("The series sum is: %lld\n", series_sum);

    return 0;
}