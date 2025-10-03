extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "pattern_proposed.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, z, limit;

    a = 0;
    b = 0;
    z = __VERIFIER_nondet_int();

    assume_abort_if_not(z > 0);
    limit = z * 2;

    while (a < limit) {
        if (a % 2 == 0) {
            b = b + a;
        } else {
            b = b - a;
        }
        a = a + 1;
    }

    // Ensure the computational logic maintains a condition
    __VERIFIER_assert(b > -limit);
    return 0;
}