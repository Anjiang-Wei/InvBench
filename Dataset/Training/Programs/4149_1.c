#include <stdio.h>
#include <stdlib.h>

extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated_program.c", 4, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

typedef struct {
    int a;
    int b;
} pair_t;

pair_t update_pair(pair_t p) {
    p.a = p.a + 1;
    p.b = p.b + 2;
    return p;
}

int main() {
    pair_t p;
    p.a = 0;
    p.b = 0;
    int n = __VERIFIER_nondet_int();

    if (n < 0 || n > 100) {
        // Limit n to a reasonable range for verification
        n = 10;
    }

    for (int i = 0; i < n; i++) {
        p = update_pair(p);
        __VERIFIER_assert(2 * p.a == p.b); // maintain invariant: b = 2 * a
    }

    __VERIFIER_assert(2 * p.a == p.b); // final check of the invariant

    printf("Final values: p.a = %d, p.b = %d\n", p.a, p.b);
    return 0;
}