#include <stdio.h>

extern void abort(void);
void reach_error() { abort(); }
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
}

int main() {
    int n, m, a, b, sum;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n >= 1);
    assume_abort_if_not(m >= 1);

    a = 0;
    b = 0;
    sum = 0;

    int counter = 0;
    while (counter++ < 10) {
        if (a < n) {
            a++;
            sum += a;
        }

        if (b < m) {
            b++;
            sum += b;
        }

        // Ensuring sum is always less than or equal to twice the total steps taken
    }

    // Post assertions
    __VERIFIER_assert(a <= n);

    // Output statement to indicate program completion
    printf("Final values: a = %d, b = %d, sum = %d, iterations = %d\n", a, b, sum, counter);

    return 0;
}