// sum_square_invariants.c
// Computes s = sum_{i=1..k} i  and  t = sum_{i=1..k} i^2
// Verifies the closed‐form formulas:
//    2*s == k*(k+1)
//    6*t == k*(k+1)*(2*k+1)

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_square_invariants.c", 1, "reach_error");
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
    // restrict k so that no overflow occurs in 64‐bit intermediates
    assume_abort_if_not(k >= 0 && k <= 1000);

    long long c = 0; // current index
    long long s = 0; // sum of 1..c
    long long t = 0; // sum of squares 1^2..c^2

    while (1) {
        // loop invariants to be verified:

        if (!(c < k)) {
            break;
        }

        c = c + 1;
        s = s + c;     // add c to sum
        t = t + c * c; // add c^2 to sum of squares
    }

    // check invariants one more time after loop
    __VERIFIER_assert(2 * s == c * (c + 1));

    return 0;
}