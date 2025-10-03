#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error(void) { __assert_fail("0", "new_program.c", __LINE__, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int a, b, limit, sum;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    limit = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 5);
    assume_abort_if_not(b >= 0 && b <= 5);
    assume_abort_if_not(limit >= 10 && limit <= 100);

    sum = 0;
    int counter = 0;

    while (counter < limit) {
        __VERIFIER_assert(sum >= 0);

        int fib = fibonacci(counter % 10);
        if (fib % 2 == 0) {
            sum += a * fib;
        } else {
            sum += b * fib;
        }

        counter++;
    }

    printf("The computed sum is: %d\n", sum);

    // Final assertion to verify some condition after loop execution

    return 0;
}