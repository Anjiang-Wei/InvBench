#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int sum_of_powers(int num, int max_exp) {
    int sum = 0;
    for (int i = 1; i <= max_exp; i++) {
        sum += power(num, i);
    }
    return sum;
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int base = __VERIFIER_nondet_int();
    int max_exp = __VERIFIER_nondet_int();

    assume_abort_if_not(base > 0 && base <= 5);
    assume_abort_if_not(max_exp > 0 && max_exp <= 3);

    int computed_sum = sum_of_powers(base, max_exp);
    int expected_sum = 0;
    int result = base;

    for (int i = 1; i <= max_exp; i++) {
        expected_sum += result;
        result *= base;
    }

    // Verification condition to be analyzed by verification tools
    __VERIFIER_assert(computed_sum == expected_sum);

    return 0;
}