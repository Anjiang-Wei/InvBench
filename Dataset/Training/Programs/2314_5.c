#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "generated.c", 5, "reach_error");
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

int main() {
    int x = 0, y = 0;

    // Initialize x and y with non-deterministic values
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();

    // Assume some initial conditions
    assume_abort_if_not(x >= 0 && x <= 10);
    assume_abort_if_not(y >= 0 && y <= 10);

    int count = 0;

    // Main loop, perform operations based on x and y
    while (count < 20) {
        if (x + y < 15) {
            x++;
        } else {
            y--;
        }

        count++;
    }

    // Final assertions
    __VERIFIER_assert(y <= 10);

    return 0;
}