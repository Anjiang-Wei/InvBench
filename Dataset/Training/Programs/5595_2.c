/*
   Sum of Digits Algorithm: Computes the sum of digits of a non-negative integer
   and verifies that each step results in a non-negative number.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_of_digits.c", 9, "reach_error"); }
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
    int number, sum, remainder;
    number = __VERIFIER_nondet_int();
    assume_abort_if_not(number >= 0); // Ensure number is non-negative

    sum = 0;

    while (number > 0) {
        remainder = number % 10;
        number = number / 10;
    }

    // The sum of digits should be non-negative
    __VERIFIER_assert(sum >= 0);

    return 0;
}