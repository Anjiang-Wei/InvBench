#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 10, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int a, b, n;
    long long result = 1;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();

    assume_abort_if_not(a > 0);
    assume_abort_if_not(b > 0);
    assume_abort_if_not(n >= 1 && n <= 20); // Constraint bounds on n

    // Calculate a^b using repeated squaring if n is 1
    if (n == 1) {
        int base = a;
        int exp = b;

        while (exp != 0) {
            if (exp % 2 == 1) {
                result *= base;
            }
            base *= base;
            exp /= 2;
        }
    }

    // Another computation leading to summation
    int sum = 0;
    if (n > 1) {
        for (int i = 0; i < b; ++i) {
            sum += a;
        }
        result = sum;
    }

    __VERIFIER_assert(result >= a); // A basic assertion to verify

    return 0;
}