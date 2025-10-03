#include <assert.h>
#include <stdbool.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

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

// Program with meaningful computational logic using nested loops
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int x, y;
    int sum = 0, diff = 0;
    int outer_limit = 10;
    assume_abort_if_not(a >= 0 && b >= 0 && b <= outer_limit);

    x = 0;
    y = 0;

    // Outer loop based on b
    while (y < b) {
        x = 0;

        // Nested loop with accumulating logic
        while (x < a) {
            sum += x + y;
            diff -= x;
            x++;
        }

        y++;
    }

    // Condition after loops
    __VERIFIER_assert(diff <= 0);

    return 0;
}