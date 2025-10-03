#include <assert.h>
#include <stdbool.h>

extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

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
    unsigned int n;     // Number of terms
    int term, sum;      // Current term and sum of terms
    unsigned int c = 0; // Counter
    n = __VERIFIER_nondet_uint();

    assume_abort_if_not(n > 0 && n <= 10); // Let's n be bounded for verification

    sum = 0;
    term = 1;

    while (c < n) {
        __VERIFIER_assert(term > 0); // Ensure term is positive in each iteration
        sum += term;                 // Add term to the sum
        term *= 2;                   // Next term in the series: geometric progression multiplying by 2
        c++;
    }

    // Postcondition: sum of series should be a power of two minus one

    return 0;
}