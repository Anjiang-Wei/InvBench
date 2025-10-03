#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }

extern void __VERIFIER_assert(int cond);

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
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int x, y, n;
    x = __VERIFIER_nondet_int();
    y = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    // Ensure meaningful constraint conditions
    assume_abort_if_not(x >= 0 && x <= 100);
    assume_abort_if_not(y >= 0 && y <= 100);
    assume_abort_if_not(n > 0 && n < 10000);

    int i;
    long long result = 1;

    // Basic loop with arithmetic operations
    for (i = 0; i < n; i++) {
        result += (x * y) % 1000;
        if (result > 1000000) {
            result -= 1000000;
        }
    }

    // Adding a simple assertion
    if (n > 0) {
        __VERIFIER_assert(result >= 0);
    }

    // Print the result to check correctness
    printf("Final Result: %lld\n", result);

    return 0;
}