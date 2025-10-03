#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
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

int global_counter = 0;

int fibonacci(int n) {
    int a = 0, b = 1, fib = 0, i;
    if (n < 0) {
        return -1;
    }
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    for (i = 2; i <= n && global_counter++ < 10; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return fib;
}

int main() {
    int m = __VERIFIER_nondet_int();
    if (m < 0 || m > 10) {
        assume_abort_if_not(0);
    }

    int result = fibonacci(m);

    int condition = (m < 0 || (result >= 0 && result <= 55));
    __VERIFIER_assert(condition);

    printf("Fibonacci of %d is %d\n", m, result);
    return 0;
}