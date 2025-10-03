#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main() {
    int a, b;
    long long x, y, z;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Define some constraints for a and b
    if (a < 0 || a > 20) {
        abort();
    }
    if (b < 0 || b > 20) {
        abort();
    }

    x = 1;
    y = 1;
    z = (long long)a * a + (long long)b * b;

    while (x < 1000) {
        if (x > 50) {
            y += x * a;
        } else {
            y += x * b;
        }

        __VERIFIER_assert(y >= 0); // Ensure y always stays non-negative

        x = x + 1;

        if (y > z) {
            break;
        }
    }

    printf("x: %lld, y: %lld, z: %lld\n", x, y, z);
    return 0;
}