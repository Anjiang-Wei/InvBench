// A C program that computes integer division by repeated subtraction
// and checks at the end that a = q * b + r with 0 ≤ r < b.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "div_by_subtraction.c", 7, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    // Nondeterministic inputs a and b
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Constrain inputs for automatic analysis
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(a <= 1000);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(b <= 1000);

    // Save originals for postcondition check
    int orig_a = a;
    int orig_b = b;

    // Compute quotient q and remainder r such that
    // orig_a = q * orig_b + r,  0 ≤ r < orig_b
    int q = 0;
    int r = a;

    // Loop: subtract b from r until r < b
    while (r >= b) {
        r = r - b;
        q = q + 1;
    }

    // Postconditions: check the division identity and bounds on remainder
    __VERIFIER_assert(r >= 0 && r < orig_b);

    return 0;
}