#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int __VERIFIER_nondet_int(void) {
    int val;
    // Replace with meaningful nondeterministic value generation if needed
    scanf("%d", &val);
    return val;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, c;
    long long sum = 0, product = 1;
    a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 20);

    b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 20);

    c = __VERIFIER_nondet_int();
    assume_abort_if_not(c >= 0 && c <= 20);

    int i = 0;

    // First loop: Calculate sum of first 'a' numbers
    while (i < a) {
        sum += i;
        i++;
    }

    // Second loop: Calculate product of number 'b' reduced by 1 each time
    for (int j = b; j > 0; j--) {
        product *= j;
    }

    // Third loop: A simplistic operation over range of 'c' for validation
    int x = 0;
    int y = c * 2;

    while (x < c) {
        x++;
        y -= 2;
        __VERIFIER_assert((c * 2 - y) == 2 * x);
    }

    // Final assertion based on all operations

    return 0;
}