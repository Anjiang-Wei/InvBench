#include <assert.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int counter = 0;

int main() {
    int a, b, c, sum, n;

    n = __VERIFIER_nondet_int();
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    if (n <= 0) {
        return 0;
    }

    sum = a + b + c;

    // Ensure that initial values are non-negative
    if (a < 0 || b < 0 || c < 0) {
        return 0;
    }

    while (counter < n) {

        // Increment each variable by different logic every loop iteration
        if (counter % 3 == 0) {
            a++;
        } else if (counter % 3 == 1) {
            b++;
        } else {
            c++;
        }

        sum++; // reflect the increment in sum too
        counter++;
    }

    __VERIFIER_assert(sum == a + b + c);
    return 0;
}