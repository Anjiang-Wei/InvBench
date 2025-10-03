#include <stdio.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { __assert_fail("0", "example.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Initial constraints
    if (!(a >= 0 && b >= 0 && c >= 0 && a + b + c == 100)) {
        return 0;
    }

    int count = 0;
    while (count < 50) {
        if (count % 2 == 0) {
            a += 1;
            b -= 1;
        } else {
            b += 1;
            c -= 1;
        }
        count++;
    }

    // Final assertions
    __VERIFIER_assert(a >= 0);

    printf("a = %d, b = %d, c = %d\n", a, b, c);

    return 0;
}