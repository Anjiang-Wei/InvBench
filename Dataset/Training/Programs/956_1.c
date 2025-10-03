/* Sum of consecutive numbers and factorial-like computation */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sumfact.c", 4, "reach_error"); }
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
    assume_abort_if_not(n >= 1); // Ensuring n is a positive integer

    sum = 0;
    product = 1;

    int counter = 0;
    while (counter++ < 5) {
        if (n == 0) {
            break;
        }

        sum = sum + n;         // Accumulate sum of numbers
        product = product * n; // Calculate product in a factorial-like fashion
        n = n - 1;
    }

    // At this point, sum and product contain computations based on n
    // Verification checks
    __VERIFIER_assert(sum >= 0);
    return 0;
}