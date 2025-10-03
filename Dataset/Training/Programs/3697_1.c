extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 6, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);

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

int main() {
    unsigned int u, v, max_iterations;
    unsigned long long sum, product;
    int i;

    u = __VERIFIER_nondet_uint();
    v = __VERIFIER_nondet_uint();

    sum = 0;
    product = 1;
    max_iterations = 100;

    // Main logic
    for (i = 0; i < max_iterations; i++) {
        sum += u * v;
        product *= 2;

        if (product > 1e9) {
            break;
        }
    }

    // Ensure the results are below an arbitrary large number
    assume_abort_if_not(sum < 1e8);
    assume_abort_if_not(product <= 1e9);

    // Final verification assert
    __VERIFIER_assert((sum < 1e8) && (product <= 1e9));

    return 0;
}