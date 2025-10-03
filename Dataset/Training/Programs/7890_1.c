#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 7, "reach_error"); }

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
}

extern int __VERIFIER_nondet_int();

int main() {
    int n, x = 0, y = 0, z = 0;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);
    assume_abort_if_not(n <= 1000000); // constraints to limit the loop iterations

    // Simple computations based on similar pattern as seen:
    int array1[3] = {0}; // A small array to hold some values
    int array2[3] = {0};

    for (int i = 0; i < n; i++) {
        int choice = i % 3; // Cycle among 3 states: 0, 1, 2
        if (choice == 0) {
            x += 1;
        } else if (choice == 1) {
            y += 2;
            array1[1] += y; // Populate array1 dynamically
        } else {
            z += 3;
            array2[2] = z * i; // Populate array2 conditionally
        }

        __VERIFIER_assert(x + y + z >= i);
    }

    return 0;
}