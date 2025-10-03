#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

int compute_sum(int a, int b) {
    return a + b;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int total = 0;
    int limit = 10;

    if (a > 0 && b > 0 && a + b < 20) {
        for (int i = 0; i < limit; i++) {
            _Bool flag = __VERIFIER_nondet_bool();
            if (flag) {
                total += compute_sum(a, b);
            } else {
                total += compute_sum(b, a);
            }
        }
        __VERIFIER_assert(total >= 0);
    }

    return 0;
}