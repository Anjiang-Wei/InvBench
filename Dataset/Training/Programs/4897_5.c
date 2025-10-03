#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom-program.c", 4, "reach_error"); }
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

int __VERIFIER_nondet_int() {
    return rand() % 100; // Generates numbers between 0 and 99
}

int main() {
    int a = 0, b = 0, c = 0, d = 0;
    int target = 150;
    int count = 0;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();
    d = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 1 && a <= 50);
    assume_abort_if_not(b >= 1 && b <= 50);
    assume_abort_if_not(c >= 1 && c <= 50);
    assume_abort_if_not(d >= 1 && d <= 50);

    while (count < 1000) {
        int sum = a + b + c + d;

        if (sum == target) {
            break;
        }

        if (sum < target) {
            a++;
            b++;
            c++;
            d++;
        } else {
            a--;
            b--;
            c--;
            d--;
        }

        count++;
    }

    __VERIFIER_assert(count <= 1000);

    return 0;
}