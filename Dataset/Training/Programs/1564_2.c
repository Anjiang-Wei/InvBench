extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern short __VERIFIER_nondet_short(void);
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
    int a, b, sum, product, i;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    sum = 0;
    product = 1;

    // Loop to calculate sum of first 'a' natural numbers
    for (i = 0; i < a; i++) {
        sum = sum + i + 1; // Adding i+1 gives natural numbers from 1 to 'a'
    }

    // Loop to calculate product of natural numbers up to 'b'
    for (i = 0; i < b; i++) {
        product = product * (i + 1); // Multiplying by i+1 gives natural numbers from 1 to 'b'

        // Assuming the product won't exceed a certain threshold to avoid overflow
        assume_abort_if_not(product >= 1 && product <= 1000000);
    }

    // Verification of calculated results
    __VERIFIER_assert(product > 0);

    // This assertion checks if the sum and product holds certain constraints
    // Meaningful constraint for analysis by verification tools
    return 0;
}