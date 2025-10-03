// integer square root by binary search
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "int_sqrt.c", 3, "reach_error"); }

extern unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int n = __VERIFIER_nondet_uint();

    unsigned int low = 0;
    unsigned int high;
    /* Choose high so that high*high > n, avoiding overflow */
    if (n >= 2) {
        high = (n >> 1) + 1;
    } else {
        high = n + 1;
    }

    /* Binary search for floor(sqrt(n)) */
    while (high - low > 1) {
        unsigned int mid = low + (high - low) / 2;
        unsigned long long sq = (unsigned long long)mid * mid;
        if (sq <= n) {
            low = mid;
        } else {
            high = mid;
        }
    }

    unsigned int r = low;
    /* Verify: r^2 <= n < (r+1)^2 */
    __VERIFIER_assert((unsigned long long)r * r <= n);

    return 0;
}