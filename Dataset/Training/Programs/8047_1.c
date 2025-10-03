#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int();
extern _Bool __VERIFIER_nondet_bool();

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
    int lower_bound = 5;
    int upper_bound = 15;
    int a, b, fib_n;

    a = __VERIFIER_nondet_int();
    b = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= lower_bound && a <= upper_bound);
    assume_abort_if_not(b >= lower_bound && b <= upper_bound);

    int sum = 0;

    while (__VERIFIER_nondet_bool()) {
        int n = __VERIFIER_nondet_int();

        if (n < a || n > b) {
            continue;
        }

        fib_n = fibonacci(n);
        sum += fib_n;

        if (fib_n > 1000) {
            break;
        }

        if (sum > 10000) {
            break;
        }
    }

    __VERIFIER_assert(sum >= 0);

    printf("Final sum: %d\n", sum);
    return 0;
}