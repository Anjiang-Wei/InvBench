#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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

int main() {
    int n, sum, i, count;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 50); // Limit n to make it easier for verification tools

    sum = 0;
    count = 0;
    i = 1;

    while (i <= n) {
        sum += i;
        count++;
        i++;
    }

    // Assert if the sum of first n natural numbers is correct : sum == (n * (n + 1)) / 2

    // Assert if the count of numbers added equals n
    __VERIFIER_assert(count == n);

    printf("Sum of first %d natural numbers is %d\n", n, sum);
    return 0;
}