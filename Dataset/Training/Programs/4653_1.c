// Exponentiation by squaring versus naive multiplication
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((nothrow, __leaf__)) __attribute__((noreturn));
void reach_error() { __assert_fail("0", "pow-ll.c", 10, "reach_error"); }

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
    int b0 = __VERIFIER_nondet_int();
    int e0 = __VERIFIER_nondet_int();
    assume_abort_if_not(b0 >= 0 && b0 <= 5);
    assume_abort_if_not(e0 >= 0 && e0 <= 5);

    long long base = b0;
    long long exp = e0;
    long long result1 = 1;

    // Exponentiation by squaring loop
    while (exp > 0) {
        if (exp % 2 == 1) {
            result1 *= base;
        }
        base *= base;
        exp /= 2;
    }

    // Naive multiplication loop
    long long result2 = 1;
    for (int i = 0; i < e0; i++) {
        result2 *= b0;
    }

    __VERIFIER_assert(result1 == result2);
    return 0;
}