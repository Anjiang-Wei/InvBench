/*
    Exponential Growth Simulation

    This program simulates exponential growth using a simple model.
    The population size `p` grows by a factor of `r` each iteration,
    simulating exponential growth. The program verifies that the growth
    factor and population size follow the expected grows behavior.
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "exponential_growth.c", 7, "reach_error"); }
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
    int r, n, t;
    long long p, growth, expected;

    r = __VERIFIER_nondet_int();
    assume_abort_if_not(r >= 1 && r <= 10); // Growth rate
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 100); // Initial population

    t = __VERIFIER_nondet_int();
    assume_abort_if_not(t >= 1 && t <= 10); // Time periods

    p = n;
    growth = 1;
    expected = n;

    while (t-- > 0) {
        growth *= r;
        p *= r;
    }

    expected = n * growth;
    __VERIFIER_assert(p == expected);

    return 0;
}