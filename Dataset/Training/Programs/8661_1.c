#include <assert.h>
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);

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
    int a = 0; // Initialize a to 0
    int b = 1; // Initialize b to 1
    int n = __VERIFIER_nondet_int();

    if (!(n > 0)) {
        return 0; // Assume n is positive
    }
    int i;

    // A loop that simulates a fibonacci sequence modification
    for (i = 0; i < n; i++) {
        int temp = a;
        a = b;
        b = temp + b;

        // Ensure some basic numerical properties
        __VERIFIER_assert(a >= 0); // a should always be non-negative
        __VERIFIER_assert(b >= 0); // b should always be non-negative
    }

    // Verify the final values maintain a condition
    int sum = a + b;
}