#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_example.c", 5, "reach_error"); }
extern void abort(void);
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
int __VERIFIER_nondet_int(void);
_Bool __VERIFIER_nondet_bool(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0, product = 1;

    // Assume some initial constraints
    assume_abort_if_not(a > 0 && a <= 50);
    assume_abort_if_not(b > 0 && b <= 50);

    // Loop that performs some computation on 'a' and 'b'
    while (a != b) {
        if (a > b) {
            a = a - b;
            sum += b;
        } else {
            b = b - a;
            product *= a;
        }
    }

    // At this point, 'a' should equal 'b'

    // Some conditions to assert
    __VERIFIER_assert(sum >= 0);

    printf("Result: gcd = %d, sum = %d, product = %d\n", a, sum, product);
    return 0;
}