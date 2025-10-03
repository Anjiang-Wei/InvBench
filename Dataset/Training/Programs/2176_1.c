#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 8, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool();
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
    // Initialize nondeterministic inputs
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    // Assume constraints on inputs
    assume_abort_if_not(n > 0 && n <= 1000);
    assume_abort_if_not(a >= 0 && a < 100);
    assume_abort_if_not(b >= 0 && b < 100);

    int counter = 0;
    long long sum = 0;

    // Main computation loop
    while (counter < n) {
        if (counter % 2 == 0) {
            sum += a;
        } else {
            sum += b;
        }
        counter++;
    }

    // Assert a property about the sum
    __VERIFIER_assert(sum >= n * 0);

    printf("Final sum: %lld\n", sum);
    return 0;
}