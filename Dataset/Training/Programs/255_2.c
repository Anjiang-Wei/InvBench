#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Verification Infrastructure */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "arith_prog.c", 9, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
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

/* Main Program Logic */
int main() {
    int d, n, i;
    long long current, limit;
    d = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    i = 0;

    assume_abort_if_not(d > 0);
    assume_abort_if_not(n >= 0 && n <= 100);

    current = 0;
    limit = n + d * 10; // A limit as an upper bound for current

    while (current <= limit) {
        // Check if the current element equals the given number n
        if (current == n) {
            break;
        }

        if (i >= 10) {
            break;
        }

        current += d;
        i++;
    }

    __VERIFIER_assert(i <= 10);

    return 0;
}