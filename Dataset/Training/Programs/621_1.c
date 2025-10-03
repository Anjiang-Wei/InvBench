/*
Computes the sum of the first n odd numbers
and verifies that it equals n^2.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_odd_squares.c", 5, "reach_error"); }
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
    int n, i, sum, odd;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 1000);

    sum = 0;
    odd = 1;
    i = 0;

    while (i < n) {
        __VERIFIER_assert(sum == i * i);
        sum = sum + odd;
        odd = odd + 2;
        i = i + 1;
    }

    return 0;
}