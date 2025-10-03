extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
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
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 20);

    long long sum = 0;
    long long product = 1;
    int i = 1;

    while (i <= n) {
        sum = sum + i;
        product = product * i;
        i++;
    }

    // Check if the sum of the first n natural numbers equals n*(n+1)/2

    // Check if 'product' is not zero, which is inherent for n>=1
    __VERIFIER_assert(product > 0);

    return 0;
}