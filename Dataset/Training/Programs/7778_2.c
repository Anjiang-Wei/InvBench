extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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
    int a, b, sum, product;
    int n = 50; // consider some finite maximum
    int counter = 0;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Precondition: ensure a and b are non-negative and less than some limit
    assume_abort_if_not(a >= 0 && b >= 0 && a < n && b < n);

    sum = 0;
    product = 1;

    while (counter < 100) {
        if (!(sum < n * n)) {
            break;
        }

        sum += a + b;
        product *= (a + 1);

        if (product > n * n) {
            break;
        }

        a++; // increment a to simulate some growth
        counter++;
    }

    // Post-condition: sum and product should be correctly bound by limits
    __VERIFIER_assert(sum < 2 * n * n);

    return 0;
}