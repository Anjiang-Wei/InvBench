#include <assert.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }
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
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(a > 0 && b > 0); // Assume a and b are positive

    int count = 0;
    int gcf = 1; // greatest common factor
    int smaller = a < b ? a : b;

    while (count < smaller) {
        count++;
        if (a % count == 0 && b % count == 0) {
            gcf = count;
        }
    }

    __VERIFIER_assert((a % gcf == 0) && (b % gcf == 0)); // gcf should divide both a and b
    __VERIFIER_assert(gcf <= a && gcf <= b);             // gcf should not be larger than either a or b

    return 0;
}