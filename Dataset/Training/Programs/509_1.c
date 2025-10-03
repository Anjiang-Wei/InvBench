// Multi-condition counter with verification-like conditions

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int a = 0, b = 0, c = 0, d = 0, e = 0;
    unsigned int max_iterations = 10;
    unsigned int limit = __VERIFIER_nondet_uint();

    if (limit == 0 || limit > max_iterations) {
        limit = max_iterations; // set default limit for safety
    }

    for (unsigned int i = 0; i < limit; i++) {
        if (i % 5 == 0) {
            a++;
        } else if (i % 4 == 0) {
            b++;
        } else if (i % 3 == 0) {
            c++;
        } else if (i % 2 == 0) {
            d++;
        } else {
            e++;
        }
    }

    __VERIFIER_assert((a + b + c + d + e) == limit);
    printf("Counts: a=%u, b=%u, c=%u, d=%u, e=%u\n", a, b, c, d, e);
    return 0;
}