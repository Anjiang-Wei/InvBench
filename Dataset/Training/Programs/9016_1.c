#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n;
    long long sum, i, factor;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    sum = 0;
    i = 1;
    factor = n * (n + 1) / 2;

    while (1) {
        // Ensures sum of the first i numbers
        if (!(i <= n)) {
            break;
        }

        sum += i;
        i++;
    }

    __VERIFIER_assert(sum == factor); // Sum of the first n natural numbers is given by factor
    printf("Sum of the first %d numbers is %lld\n", n, sum);
    return 0;
}