// Integer square‐root (floor) computation with verification
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "int_sqrt.c", 7, "reach_error");
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
int counter = 0;

int main() {
    int n = __VERIFIER_nondet_int();
    // constrain n to avoid overflow in squares
    assume_abort_if_not(n >= 0 && n <= 10000);

    int r = 0;

    // find largest r such that r*r <= n
    while (counter++ < 50) {
        long long sq = (long long)r * r;
        // r must always satisfy r*r <= n in the loop
        __VERIFIER_assert(sq <= n);

        long long next_sq = (long long)(r + 1) * (r + 1);
        if (!(next_sq <= n)) {
            break;
        }
        r++;
    }

    // post‐condition: r*r <= n < (r+1)*(r+1)
    long long final_sq = (long long)r * r;
    long long next_sq = (long long)(r + 1) * (r + 1);

    return 0;
}