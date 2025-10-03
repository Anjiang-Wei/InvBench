extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 8, "reach_error"); }

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
    int p, q, r;
    long long sum, diff, prod, i;

    // Nondeterministically initialize p and q
    p = __VERIFIER_nondet_int();
    q = __VERIFIER_nondet_int();

    // Assume certain constraints on p and q
    assume_abort_if_not(p > 0 && p <= 100);
    assume_abort_if_not(q > 0 && q <= 100);

    sum = 0;
    diff = 0;
    prod = 1;
    r = __VERIFIER_nondet_int();
    assume_abort_if_not(r >= 0 && r <= 10);

    i = 0;
    while (i < r) {
        sum += p + q;
        diff -= p - q;
        prod *= (p * q);

        __VERIFIER_assert(sum > 0 && diff + sum >= 0 && prod >= 1);

        i++;
    }

    // Post-condition verification

    return 0;
}