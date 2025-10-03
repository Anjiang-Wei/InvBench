#include <assert.h>
#include <stdlib.h>

// Function declarations for error handling and assumptions
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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

extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    int a = 0, b = 0, c = 0;

    // Assume n is within a certain range to make it interesting
    assume_abort_if_not(n >= 1 && n <= 100);

    for (int i = 0; i < n; i++) {
        a += 2;
        b += 3;
        c = b - a;
    }

    // Use assertions to check some properties at the end of the loop
    __VERIFIER_assert(c == n);

    // Additional loop to manipulate and validate another logic
    while (a > 0 && c > 0) {
        a -= 2;
        b -= 3;
        c = b - a;
    }

    // Final assertion to verify the end state

    return 0;
}