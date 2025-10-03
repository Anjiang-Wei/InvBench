#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() __attribute__((__noreturn__));
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
    return;
}

int main() {
    int a, b, c, d;
    long long result, temp1, temp2;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    d = __VERIFIER_nondet_int();

    // Constraints on input values to ensure meaningful computation
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b > 0 && b <= 5);
    assume_abort_if_not(c >= 1 && c <= 5);
    assume_abort_if_not(d >= 2 && d <= 5);

    result = 0;
    temp1 = a;
    temp2 = b;

    while (1) {
        __VERIFIER_assert(result + temp1 * temp2 == (long long)a * b);
        if (!(temp2 != 0)) {
            break;
        }

        if (temp2 % 2 == 1) {
            result = result + temp1;
            temp2 = temp2 - 1;
        }

        temp1 = 2 * temp1;
        temp2 = temp2 / 2;
    }

    temp1 = c;
    temp2 = d;

    while (temp1 < temp2) {
        temp1 = temp1 + 1;
        temp2 = temp2 - 1;
    }

    return 0;
}