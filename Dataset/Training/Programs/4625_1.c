#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "gcd.c", 9, "reach_error"); }
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

int gcd(int a, int b) {
    assume_abort_if_not(a >= 0 && b >= 0);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
        __VERIFIER_assert(a >= b); // Assert condition for verification
    }
    return a;
}

int main() {
    int input1 = 56; // Example input number 1
    int input2 = 98; // Example input number 2
    int result;

    result = gcd(input1, input2);

    return 0;
}