#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "example.c", 4, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n, result, i;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 10); // Limiting n to be in a range for controlled recursive calls

    result = 0;
    for (i = 0; i <= n; i++) {
        result += fibonacci(i);
    }

    __VERIFIER_assert(result >= 0); // The result should never be negative

    printf("The sum of Fibonacci sequence up to %d is: %d\n", n, result);
    return 0;
}