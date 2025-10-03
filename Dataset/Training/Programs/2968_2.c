#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

// Assumes a boolean condition is true; aborts otherwise
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

// Custom assert to invoke reach_error if the condition is false
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    // Ensuring input constraints
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }

    int p = 1;
    int q = 1;
    int d = 1;

    // Loop to calculate a pseudo-factorial based on given non-negative integers
    while (1) {
        // This break condition controls the loop's "done" state
        if (!(d < a + b + c)) {
            break;
        }

        d++;
        if (d % 2 == 0) {
            p *= d;
        } else {
            q *= d;
        }
    }

    // Assert that p and q have maintained certain properties
    __VERIFIER_assert(q > 0);

    return 0;
}