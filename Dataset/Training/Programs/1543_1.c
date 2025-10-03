#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new-example.c", 5, "reach_error"); }

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

unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int n = __VERIFIER_nondet_uint();
    unsigned int a = 0, b = 0;
    unsigned int sum = 0;

    // Ensure n is within a reasonable limit for computation
    assume_abort_if_not(n < 10000);

    while (n > 0) {
        if (n % 2 == 0) {
            a += n;
            n -= 2;
        } else {
            b += n;
            n -= 3;
        }
        sum = a + b;
    }

    // sum should be equal to a + b because we only use a and b to accumulate numbers from n
    __VERIFIER_assert(sum == a + b);

    printf("Final sum is: %u\n", sum);
    return 0;
}