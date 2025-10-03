/*
  Euclidean Algorithm for Computing GCD (Greatest Common Divisor)
  Based on patterns like division and geometric series
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "euclidean-gcd.c", 7, "reach_error"); }
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
    int a, b;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);

    int x = a;
    int y = b;

    while (x != y) {
        // Ensure that x and y keep reducing until they are equal
        __VERIFIER_assert(x > 0 && y > 0);

        if (x > y) {
            x = x - y;
        } else {
            y = y - x;
        }
    }

    // At this point, x and y should be equal to the gcd of a and b

    return 0;
}