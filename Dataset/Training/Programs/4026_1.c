/*
Linear Congruential Generator (LCG)
Produces a sequence of pseudo-randomized numbers using a linear congruential formula
Ensures that every generated number falls within an expected range [0, m-1]
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "lcg.c", 5, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
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
    unsigned int seed, a, c, m, n;
    unsigned int x;

    seed = __VERIFIER_nondet_uint();
    a = __VERIFIER_nondet_uint();
    c = __VERIFIER_nondet_uint();
    m = __VERIFIER_nondet_uint();
    n = __VERIFIER_nondet_uint();

    assume_abort_if_not(m > 0);
    assume_abort_if_not(n > 0);

    x = seed;

    int i = 0;
    while (i < n) { // Generate n pseudo-random numbers
        x = (a * x + c) % m;

        // Ensure the generated number is within the correct range
        __VERIFIER_assert(x < m);

        i++;
    }

    return 0;
}