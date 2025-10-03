extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;
    int diff = 0;

    assume_abort_if_not(a >= 0 && a <= 50);
    assume_abort_if_not(b >= 0 && b <= 50);

    // Loop to calculate sum and difference
    for (int i = 0; i < a; i++) {
        sum += 2; // sum = 2 * a
    }

    for (int j = 0; j < b; j++) {
        diff -= 1; // diff = -b
    }

    // Relations to be verified
    __VERIFIER_assert(diff == -b);

    // Additional loop with conditional computation
    int factor = 1;
    while (a > 0 && b > 0) {
        a--;
        b--;
        factor *= 2;
    }

    // Verify the post-conditions

    return 0;
}