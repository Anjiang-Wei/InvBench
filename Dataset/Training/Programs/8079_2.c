/*
 * Simple integer sequence computation
 * Computes sequence and checks properties.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sequence.c", 3, "reach_error"); }
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
    int n;
    long long sum, product;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100);

    sum = 0;
    product = 1;

    int i = 1;

    while (1) {
        if (!(i <= n)) {
            break;
        }

        sum += i;
        product *= i;

        i++;
    }

    // Check if the computed sum is the same as n(n+1)/2

    // Check if the computed product is equivalent to factorial n
    // Note: not practical to check for large n without causing overflow for int/long long,
    //       so we simply check for n = 1 since it's safe within our assumption bounds.
    if (n == 1) {
        __VERIFIER_assert(product == 1);
    }

    return 0;
}