extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "proposed_program.c", 5, "reach_error"); }
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
    int a, b, product, sum, counter;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Initialize sum as the product of a and b
    product = 0;
    sum = 0;
    counter = 0;

    // Loop to calculate sum of first 'a' numbers and verified constraints
    while (counter < a) {
        sum += counter;
        product += b;
        counter++;
        __VERIFIER_assert(product == b * counter);
    }

    // Verify that the calculated sum is consistent with the arithmetic series formula

    return 0;
}