#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new-program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int() {
    int val;
    scanf("%d", &val);
    return val;
}

_Bool __VERIFIER_nondet_bool() {
    int val;
    scanf("%d", &val);
    return val != 0;
}

void process(int n) {
    int x = 0, y = __VERIFIER_nondet_int();
    if (n < 1 || y < 0) {
        return;
    }

    while (n > 0) {
        _Bool choice = __VERIFIER_nondet_bool();
        if (choice) {
            x += 2;
        } else {
            y += x;
        }
        n--;
    }

    __VERIFIER_assert(x >= 0 && y >= 0);
}

int main() {
    int n = __VERIFIER_nondet_int();
    process(n);

    return 0;
}