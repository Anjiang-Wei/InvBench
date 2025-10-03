// This program verifies that the sum of the first k cubes equals
// the square of the sum of the first k integers, i.e. 1^3 + 2^3 + ... + k^3 == (1 + 2 + ... + k)^2.
// It is designed for analysis by automated verifiers.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sum_cubes_square.c", 5, "reach_error");
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
    // nondeterministic bound k
    int k = __VERIFIER_nondet_int();
    // we restrict k for 64-bit safety
    assume_abort_if_not(k >= 0 && k <= 1000);

    // c: loop counter, x: sum of integers, y: sum of cubes
    long long c = 0;
    long long x = 0;
    long long y = 0;

    while (1) {
        // Check the relation holds at the beginning of each iteration

        if (!(c < k)) {
            break;
        }

        c = c + 1;
        x = x + c;         // x = 1 + 2 + ... + c
        y = y + c * c * c; // y = 1^3 + 2^3 + ... + c^3
    }

    // Final check after the loop terminates
    __VERIFIER_assert(y == x * x);

    return 0;
}