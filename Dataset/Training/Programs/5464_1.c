#include <assert.h>
void reach_error(void) { assert(0); }

extern unsigned int __VERIFIER_nondet_uint(void);
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define MAX_VALUE 1000

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int a = 0, b = 1, c, i;

    assume_abort_if_not(n < MAX_VALUE);

    for (i = 0; i < n; i++) {
        c = a + b; // Compute the next Fibonacci number
        a = b;
        b = c;
    }

    if (n == 0) {
        __VERIFIER_assert(a == 0);
    } else if (n == 1) {
    } else {
    }

    return 0;
}