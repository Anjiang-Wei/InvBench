// A program to compute the greatest common divisor (GCD)
// of two non-negative integers using the Euclidean algorithm.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 6, "reach_error"); }
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
}

int gcd(int u, int v) {
    while (v != 0) {
        int temp = v;
        v = u % v;
        u = temp;
    }
    return u;
}

int main() {
    int x, y;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    assume_abort_if_not(x >= 0 && y >= 0 && x <= 1000 && y <= 1000);

    int result = gcd(x, y);

    // After the execution, result should be the gcd of x and y

    // In the Euclidean algorithm, gcd(x,0) is x
    if (y == 0) {
        __VERIFIER_assert(result == x);
    }
    // Likewise, gcd(0,y) is y
    else if (x == 0) {
    }

    return 0;
}