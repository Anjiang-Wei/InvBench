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

extern int __VERIFIER_nondet_int(void);

int find_factorial(int n) {
    int factorial = 1;
    while (n > 0) {
        factorial *= n;
        n--;
    }
    return factorial;
}

int main() {
    int num = __VERIFIER_nondet_int();
    if (num < 0 || num > 12) {
        // Limit the number to avoid integer overflow for factorial calculation
        return 0;
    }

    int result = find_factorial(num);

    // Verify if the last computation is correct using a property
    if (num == 0) {
    } else if (num == 1) {
    } else if (num == 2) {
    } else if (num == 3) {
        __VERIFIER_assert(result == 6);
    }

    printf("Factorial of %d is: %d\n", num, result);
    return 0;
}