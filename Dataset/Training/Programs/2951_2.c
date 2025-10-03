#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern int __VERIFIER_nondet_int(void);

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0);

    // Specific program: Calculate factorial of a number n
    int fact = 1;
    int i = 1;

    while (i <= n) {
        long long prev_fact = fact; // To avoid overflow check in __VERIFIER_assert
        fact = fact * i;
        // Invariant: The product will never be negative if there's no overflow and i <= n

        i++;
    }

    __VERIFIER_assert(fact > 0); // Assuring no overflow for moderately small n
    return 0;
}