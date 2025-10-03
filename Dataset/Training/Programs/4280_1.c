#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "factorial-ll.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);
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
    int n, factorial;
    int counter;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limit n for practical reasons

    factorial = 1;
    counter = 0;

    while (counter < n) {
        counter++;

        // Ensure multiplying by counter does not overflow
        if (factorial > 2147483647 / counter) {
            abort(); // Simulate an overflow edge case
        }

        factorial = factorial * counter;

        // Ensure property holds: factorial is at least 1.
        __VERIFIER_assert(factorial >= 1);
    }

    // Verify final properties

    // Output the result for informational purposes
    printf("Factorial of %d is %d\n", n, factorial);

    return 0;
}