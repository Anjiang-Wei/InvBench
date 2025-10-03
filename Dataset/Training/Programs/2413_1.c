#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

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
    int a = 0, b = 1, c = 1;
    int max_iterations = 1000;
    int i = 0;

    while (i < max_iterations) {
        int old_c = c;
        c = a + b; // Fibonacci sequence computation
        a = b;
        b = old_c;
        i++;

        // Verify constraints
        if (i > 2) {
            __VERIFIER_assert(c <= (a + b));
        }
    }

    // Final assertions to ensure the correctness of the computation

    printf("Fibonacci sequence computed up to %d iterations.\n", max_iterations);
    return 0;
}