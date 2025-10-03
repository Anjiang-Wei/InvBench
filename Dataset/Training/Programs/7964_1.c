#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int N, a, b, sum;
    N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N < 100); // Limit N to a reasonable number for analysis

    a = 0;
    b = 1;
    sum = 0;
    int i = 0;

    for (i = 0; i < N; i++) {
        int temp = a;
        a = b;
        b = temp + b;
    }

    i = 0;
    while (i < N) {
        sum += i * i; // Sum of squares of 0 to N-1
        i++;
    }

    __VERIFIER_assert(a <= sum + b); // Constraint to verify
    printf("Fibonacci number: %d, Sum of squares: %d\n", a, sum);

    return 0;
}