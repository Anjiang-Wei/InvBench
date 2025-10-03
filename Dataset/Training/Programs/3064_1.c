#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int factorial(int n) {
    if (n < 0) {
        return 0; // Factorial is not defined for negative numbers
    }
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += factorial(i);
    }

    // The sum of factorials 1! + 2! + 3! + 4! + 5! = 1 + 2 + 6 + 24 + 120 = 153
    __VERIFIER_assert(sum == 153);

    printf("Computed sum of factorials: %d\n", sum);
    return 0;
}