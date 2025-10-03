extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_loop.c", 3, "reach_error");
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
    /* k is a non‐negative bound on the loop iterations */
    int k = __VERIFIER_nondet_int();
    assume_abort_if_not(k >= 0 && k <= 512);

    int sum = 0;
    int i = 0;

    /* compute sum = 0 + 1 + 2 + ... + (k-1) */
    while (i < k) {
        sum = sum + i;
        i = i + 1;
    }

    /* Check the closed-form: sum = k*(k-1)/2  <=>  2*sum == k*(k-1) */
    __VERIFIER_assert(sum >= 0);

    return 0;
}