// A program to calculate the GCD (Greatest Common Divisor) of two
// non-negative integers using the Euclidean algorithm.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int m, n;
    m = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(m >= 0);
    assume_abort_if_not(n >= 0);

    if (m == 0 || n == 0) {
        // The GCD is defined as the non-zero number, or zero if both are zero
        int gcd = m == 0 ? n : m;
        return 0;
    }

    while (n != 0) {
        int temp = n;
        n = m % n;
        m = temp;
    }

    __VERIFIER_assert(m >= 0); // The GCD should always be a non-negative number

    return 0;
}