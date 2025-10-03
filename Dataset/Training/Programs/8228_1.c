#include <assert.h>
#include <stdio.h>

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error(void) { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int fibonacci(int n) {
    int a = 0, b = 1, temp;
    for (int i = 2; i <= n; i++) {
        temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int fib = fibonacci(5); // Fixed number for simplicity
    int count = 0;

    if (a < 0) {
        return 0; // Let's assume that negative values are invalid
    }

    while (__VERIFIER_nondet_bool()) {
        a++;
        count += 3;
        if (count >= 100) {
            break;
        }
    }

    __VERIFIER_assert(a >= 0);
    return 0;
}