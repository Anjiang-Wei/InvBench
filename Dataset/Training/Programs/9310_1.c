// Sum of squares series verifier
// Computes s = 1^2 + 2^2 + ... + n^2 and checks the closed‐form
//    6*s == n*(n+1)*(2*n+1)

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "sum_squares.c", 9, "reach_error");
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
    int n;
    long long c, s;

    // nondeterministic input, small bound for automatic tools
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 5);

    c = 0;
    s = 0;

    while (1) {
        // invariant: 6*s == c*(c+1)*(2*c+1)
        __VERIFIER_assert(6 * s == c * (c + 1) * (2 * c + 1));

        if (!(c < n)) {
            break;
        }

        c = c + 1;
        s = s + c * c;
    }

    // postcondition: 6*s == n*(n+1)*(2*n+1)

    return 0;
}