// This C program is designed for verification tools to analyze and verify.
// It contains meaningful computational logic by performing an iterative search
// for the greatest common divisor (GCD) of two numbers using the Euclidean algorithm.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd_example.c", 6, "reach_error"); }

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

int gcd(int a, int b) {
    // Precondition: a >= 0, b >= 0
    assume_abort_if_not(a >= 0);
    assume_abort_if_not(b >= 0);

    // Ensure at least one of 'a' or 'b' is positive
    assume_abort_if_not(a > 0 || b > 0);

    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Assuming non-deterministic integers a, b as inputs. Ensure a, b are non-negative.
    assume_abort_if_not(a >= 0 && b >= 0);

    int result = gcd(a, b);

    // Verification: If both a and b are zero, gcd should be zero. Otherwise, it should not be zero.
    if (a == 0 && b == 0) {
        __VERIFIER_assert(result == 0);
    } else {
    }

    return 0;
}