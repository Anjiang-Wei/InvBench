#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int process_value(int x, int y) {
    return (x * y) - (x + y);
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition: a >= 0, b >= 0
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    int result = 0;
    int limit = 10;

    while (b > 0 && limit > 0) {
        a += b;
        b = process_value(a, b);
        result += a;
        limit--;
    }

    printf("Result: %d\n", result);

    // Postcondition: result should be non-negative
    __VERIFIER_assert(result >= 0);

    return 0;
}