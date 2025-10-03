// This C program is intended for verification and includes both looping structures and conditional logic to evolve state variables.

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex_logic.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int();
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    // Initialize counters
    int x = a, y = b;
    int count = 0;

    // A loop that alters values of x and y under certain constraints
    while (count < 15) {
        int choice = __VERIFIER_nondet_int();
        assume_abort_if_not(choice >= 0 && choice <= 1);

        if (choice == 0 && x < 10) {
            x += 3;
        } else if (choice == 1 && y > 0) {
            y -= 2;
        }

        count++;

        // Logic checks after each iteration
        if (x > 20) {
            x = x % 20;
        }

        if (y < 0) {
            y = 0;
        }
    }

    // Final assertions to be verified
    __VERIFIER_assert(y >= 0 && y <= 10);

    return 0;
}