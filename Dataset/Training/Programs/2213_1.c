#include <assert.h>
#include <stdlib.h>

void reach_error() {
    __assert_fail("0", "generated.c", 3, "reach_error");
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int result = 0;
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    int limit = __VERIFIER_nondet_int(); // Arbitrary loop limit
    if (limit <= 0) {
        return 0;
    }

    while (__VERIFIER_nondet_bool() && limit-- > 0) {
        if (a % 2 == 0) {
            result += b; // Repeat addition simulating multiplication
        }
        a /= 2;
        b *= 2;

        if (a == 0) {
            break;
        }
    }

    // Check if computation followed the expected logic
    __VERIFIER_assert(result >= 0);

    return 0;
}