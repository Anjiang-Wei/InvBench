extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
    int a, b, n;
    long long f1, f2, next;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Assume sensible conditions for init values and loop bound
    assume_abort_if_not(n > 0 && n <= 20);
    assume_abort_if_not(a > 0 && b > 0 && a < b);

    f1 = a;
    f2 = b;

    while (n > 0) {
    }

    // Post-conditions to check at the end of loop
    __VERIFIER_assert(f1 > a); // ensure f1 is always greater than initial a
    __VERIFIER_assert(f2 > b); // ensure f2 is always greater than initial b

    return 0;
}