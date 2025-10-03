// This is a complete C program designed for verification by automated tools.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 10, "reach_error"); }

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
    int a, b, c;
    int sum, product;
    int threshold = 100;

    // Initializing variables with non-deterministic values
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    // Assume conditions for the input values
    assume_abort_if_not(a >= 1 && a <= 10);
    assume_abort_if_not(b >= 1 && b <= 10);
    assume_abort_if_not(c >= 1 && c <= 10);

    // Initial computations
    sum = a + b + c;
    product = a * b * c;

    int loop_counter = 0;

    // Loop with a condition to modify the product and assert properties
    while (loop_counter < 10 && product < threshold) {
        // Add some non-deterministic value and recompute sum and product
        int increment = __VERIFIER_nondet_int();
        assume_abort_if_not(increment >= 0 && increment <= 5);

        sum += increment;
        product *= (1 + (increment % 2)); // slightly increases or keeps same

        // Assertion checks
        __VERIFIER_assert(product >= a * b * c);

        loop_counter++;
    }

    // Final assertion to ensure loop achieved several computations

    return 0;
}