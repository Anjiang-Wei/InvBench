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

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

/*
Compute the Fibonacci sequence and ensure the relation
f(n) = f(n-1) + f(n-2) holds along with constraints on the values.
*/

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 50);

    long long f_prev = 0;
    long long f_curr = 1;
    int counter = 2;

    while (__VERIFIER_nondet_bool()) {
        __VERIFIER_assert(f_curr >= 0); // Basic condition to ensure non-negative Fibonacci numbers
        if (counter > n) {
            break;
        }

        long long temp = f_curr;
        f_curr = f_curr + f_prev;
        f_prev = temp;

        counter++;
    }

    return 0;
}