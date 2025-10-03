#include <assert.h>
#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int square(int num) {
    return num * num;
}

int main() {
    int n, sum, i;

    // Assume constraints for n
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 100);

    sum = 0;
    i = 1;

    // Loop to calculate the sum of squares up to n
    while (i <= n) {
        sum += square(i);

        // Asserting the loop invariant
        __VERIFIER_assert(sum >= 0);

        i++;
    }

    // Assert a property after the loop

    return 0;
}