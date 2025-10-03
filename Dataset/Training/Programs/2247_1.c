#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 5, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : { reach_error(); }
    }
    return;
}

int main() {
    int n, m, count;
    n = __VERIFIER_nondet_int();
    m = __VERIFIER_nondet_int();

    assume_abort_if_not(n > 0 && m > 0 && n <= 1000 && m <= 1000);

    int array[n];
    for (int i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    count = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] % m == 0) {
            count++;
        }
    }

    __VERIFIER_assert((count >= 0) && (count <= n));

    printf("Count of elements divisible by %d is: %d\n", m, count);

    return 0;
}