#include <assert.h>
#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "derived_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a, b, c;
    int target = __VERIFIER_nondet_int(); // The target value to reach
    assume_abort_if_not(target > 0 && target < 100);

    a = 0;
    b = 1;
    c = 0;

    while (c < target) {
        int temp = a + b;
        a = b;
        b = temp;
        c++;

        // Ensure b + a >= a holds for this loop's Fibonacci progression
        __VERIFIER_assert(b >= a);
    }

    // Check post condition that the `c` value is exactly target

    return 0;
}