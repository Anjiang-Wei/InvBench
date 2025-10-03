#include <assert.h>
#include <stdbool.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = 1;

    // Ensure a starts as a non-negative value
    if (a < 0) {
        return 0;
    }

    // The loop will divide a by 2 until it becomes less than or equal to 1
    while (a > 1) {
        // This condition ensures the loop is bounded and observable

        if (a % 2 == 0) {
            a = a / 2;
        } else {
            a = (a - 1) / 2;
        }
        b++;
    }

    // Post condition asserts that a should be 0 or 1 after the loop execution
    __VERIFIER_assert(a == 0 || a == 1);

    return 0;
}