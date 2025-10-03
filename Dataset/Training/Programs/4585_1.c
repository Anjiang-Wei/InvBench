#include <stdbool.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main(void) {
    int a, b, c;
    int sum = 0;
    int count = 0;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    c = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0 && a <= 100);
    assume_abort_if_not(b > 0 && b <= 100);
    assume_abort_if_not(c > 0 && c <= 100);

    while (count < 10) {
        sum += a * b + c;
        if (sum > 1000) {
            sum -= 500;
        }
        count++;
    }

    __VERIFIER_assert(sum >= 0);
    printf("Final Sum: %d\n", sum);
    return 0;
}