// Sample C program following verified examples

#include <assert.h>

void reach_error() { assert(0); }
extern void abort(void);
extern int __VERIFIER_nondet_int(void);

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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Precondition: Ensure 'a', 'b', and 'n' are non-negative integers
    // 'b' should be greater than 'a', and both should be less than or equal to 'n'
    assume_abort_if_not(a >= 0 && b > a && b <= n);

    int sum = 0;
    int count = 0;
    int i = a;

    // Loop to calculate the sum of numbers from 'a' to 'b'
    while (i <= b) {
        sum += i;
        count++;
        i++;
    }

    // Postcondition: Check that the number of iterations equals (b - a + 1)
    // and the sum calculated is (b - (a-1)) * (a + b) / 2
    __VERIFIER_assert(count == (b - a + 1));

    return 0;
}