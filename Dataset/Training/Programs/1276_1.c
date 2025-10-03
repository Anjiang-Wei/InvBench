#include <assert.h>
#include <stdio.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
The below program incrementally builds a total sum from 1 to a specified limit
by adding each successive odd number.
The calculation can be represented as 1 + 3 + 5 + ... + (2*n - 1).
*/

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 1) {
        return 0;
    }

    int sum = 0;
    int i = 0;
    int current_odd = 1;

    // Invariant: sum is the sum of odd numbers from 1 to current_odd - 2
    while (i < n) {
        __VERIFIER_assert(sum == i * i);
        sum += current_odd;
        current_odd += 2;
        i++;
    }

    // For understanding purpose, print the sum here
    printf("The sum of the first %d odd numbers is %d\n", n, sum);

    return 0;
}