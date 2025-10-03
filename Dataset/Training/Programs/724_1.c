// A program that computes 2^k by repeated doubling and then checks the final result.
// It is meant for automated verification tools.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "power2.c", 20, "reach_error");
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
        abort();
    }
}

int main() {
    int k = __VERIFIER_nondet_int();
    // Constrain k so that 2^k does not overflow a 32-bit int (on typical platforms)
    assume_abort_if_not(k >= 0);
    assume_abort_if_not(k < 31);

    int result = 1;
    int i = 0;
    int counter = 0;

    // Repeatedly double 'result' until we've done it k times
    while (counter++ < 100) {
        if (i >= k) {
            break;
        }
        result = result * 2;
        i = i + 1;
    }

    // At loop exit we must have performed exactly k doublings
    __VERIFIER_assert(i == k);
    // And the result must equal 2^k

    return 0;
}