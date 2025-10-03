extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_loop.c", 3, "reach_error"); }

int __VERIFIER_nondet_int();

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int a = 0;
    int b = 1;
    int limit = __VERIFIER_nondet_int();

    if (!(limit > 0 && limit <= 100)) {
        return 0;
    }

    while (a < limit) {
        if (a % 2 == 0) {
            b *= 2;
        } else {
            b += 3;
        }
        a++;
    }

    // This assertion verifies that `b` is always greater than `limit` after the loop,
    // given the specific pattern of addition and multiplication applied throughout the loop.
    __VERIFIER_assert(b > limit);

    return 0;
}