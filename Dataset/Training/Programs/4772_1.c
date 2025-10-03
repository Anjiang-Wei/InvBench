#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
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
extern _Bool __VERIFIER_nondet_bool();

int sum_to_n(int n) {
    return (n * (n + 1)) / 2; // The sum of the first n natural numbers
}

int main() {
    int n;
    int sum = 0;
    n = __VERIFIER_nondet_int(); // Nondeterministic input for n
    if (n <= 0) {
        return 0; // Ensure n is positive
    }

    // Loop to calculate the sum using iterative addition
    for (int i = 1; i <= n; i++) {
        sum += i;
        __VERIFIER_assert(sum == sum_to_n(i)); // Verify the sum at each step
    }

    printf("The sum of the first %d natural numbers is: %d\n", n, sum);
}