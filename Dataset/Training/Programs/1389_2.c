#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-program.c", 5, "reach_error"); }
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
    int a, b, t;
    int sum = 0, product = 1, counter = 0;

    // Let's consider `a` and `b` are non-deterministically generated integers
    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();

    // Assume reasonable constraints
    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);

    t = a;
    while (t < b) {
        sum += t;
        product *= (t == 0 ? 1 : t + 1);
        t++;
        counter++;

        // Check if calculated sum and product satisfy a specified condition
        if (!(sum <= (a + b) * counter && product >= 1)) {
            break;
        }
    }

    // Final assertions that should hold if the loop executes correctly
    __VERIFIER_assert(product >= 1);

    printf("Sum: %d, Product: %d\n", sum, product);
    return 0;
}