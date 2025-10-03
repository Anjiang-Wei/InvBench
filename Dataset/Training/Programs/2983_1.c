#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { assert(0); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a, b, c;
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b >= 0 && c >= 0);

    int sum = 0, factor = 1;

    // Ensure a, b, c are distinct non-negative numbers
    assume_abort_if_not(a != b && b != c && a != c);

    while (factor <= 10) {
        // Calculate a sum based on multiples of a, b, and c
        if (factor % 2 == 0) {
            sum += a * factor;
        } else {
            sum += b * factor;
        }

        if (factor % 3 == 0) {
            sum += c * factor;
        }

        factor++;
    }

    // We expect that sum is bounded by a known factor
    __VERIFIER_assert(sum < (a + b + c) * 40);

    return 0;
}