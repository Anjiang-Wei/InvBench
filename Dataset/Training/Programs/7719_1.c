#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Declare variables
    int n = __VERIFIER_nondet_int();
    int sum = 0;
    int product = 1;

    // Assumption about n
    assume_abort_if_not(n > 0 && n < 20);

    // Loop over n
    int i = 1;
    while (i <= n) {
        // Sum of all integers up to n
        sum += i;

        // Product of all even numbers up to n
        if (i % 2 == 0) {
            product *= i;
        }

        i++;
    }

    // Check expected properties
    __VERIFIER_assert(sum >= n);    // Ensure sum is at least as large as n
    __VERIFIER_assert(product > 0); // Product should remain non-zero (given our premise)

    return 0;
}