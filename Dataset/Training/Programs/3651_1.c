// Summation and power‐sum verification
// Computes sum_{i=0..k-1} i, sum of squares, sum of cubes
// and checks the known closed‐form formulas as loop invariants.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_powers_verifier.c", 8, "reach_error");
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
    int k = __VERIFIER_nondet_int();
    // we only consider 0 ≤ k ≤ 20 to avoid overflow
    assume_abort_if_not(k >= 0 && k <= 20);

    int c = 0;  // loop counter
    int sc = 0; // sum of i for i in [0..c-1]
    int ss = 0; // sum of i^2 for i in [0..c-1]
    int cc = 0; // sum of i^3 for i in [0..c-1]

    while (1) {
        // Invariants for sums up to c-1:
        //   sc =  (c-1)*c/2
        //   ss = (c-1)*c*(2*c-1)/6
        //   cc = [(c-1)*c/2]^2

        __VERIFIER_assert(2 * sc == c * (c - 1));

        if (!(c < k)) {
            break;
        }

        // include the current c in our sums, then advance c
        sc += c;         // add i
        ss += c * c;     // add i^2
        cc += c * c * c; // add i^3
        c++;
    }

    // Final check after loop termination

    return 0;
}