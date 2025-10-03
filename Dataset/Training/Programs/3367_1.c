#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 7, "reach_error"); }

extern int __VERIFIER_nondet_int();
void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    unsigned int a = 0;
    unsigned int b = 0;
    int target = __VERIFIER_nondet_int();

    // Setup initial constraints
    if (!(target > 0)) {
        return 0;
    }
    if (!(target < 1000)) {
        return 0;
    }

    // Loop that performs computations based on some condition
    while (b < target && a < target / 2) {
        if (a % 2 == 0) {
            a += 3;
        } else {
            b += 5;
        }

        // Safety net to prevent infinite loop in case of logic error (for verification analysis)
        if (b > 1000 || a > 1000) {
            break;
        }
    }

    // Assert to ensure intended behavior after loop
    __VERIFIER_assert(b >= target || a >= target / 2);

    return 0;
}