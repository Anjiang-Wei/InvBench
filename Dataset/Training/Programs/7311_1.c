// Sum of squares program:
// Computes S = 1^2 + 2^2 + ... + n^2 and checks the closed‐form formula
//   S == n*(n+1)*(2*n+1)/6

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_squares.c", 12, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    // restrict n so that the loop is finite and there's no overflow
    assume_abort_if_not(n >= 0);
    assume_abort_if_not(n <= 10);

    long long S = 0;
    int i = 1;

    // compute sum of squares
    while (i <= n) {
        S += (long long)i * i;
        i++;
    }

    // check the known closed‐form: 1^2 + ... + n^2 = n*(n+1)*(2*n+1)/6
    __VERIFIER_assert(6 * S == (long long)n * (n + 1) * (2 * n + 1));

    return 0;
}