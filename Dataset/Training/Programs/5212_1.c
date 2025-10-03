#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprog.c", 6, "reach_error"); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int MAX_SIZE = 1000000;

int main() {
    int n = __VERIFIER_nondet_int();
    if (!(n >= 1 && n <= MAX_SIZE)) {
        return 0;
    }

    int sum = 0;
    int product = 1;
    int count = 0;
    int i = n;

    while (i > 0) {
        if (n % i == 0) {
            // If i is a divisor of n, include in some computation
            sum += i;
            product *= i;
            count++;
        }
        i--;
    }

    // Ensuring that the computation meets some condition
    __VERIFIER_assert(sum >= n && count > 0);

    return 0;
}