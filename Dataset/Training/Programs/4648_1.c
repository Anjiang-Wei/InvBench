#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    int result = 1;

    // Precondition: n is between 0 and 5 for computational feasibility
    if (!(n >= 0 && n <= 5)) {
        return 0;
    }

    // Loop: calculating factorial iteratively
    int i = 1;
    while (i <= n) {
        result *= i;
        i++;
    }

    // Validate the result using recursive factorial (as a checker)
    int expected = factorial(n);
    __VERIFIER_assert(result == expected);

    return 0;
}