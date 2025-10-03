#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }
int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define SIZE 10000000

int main() {
    unsigned int n = 0, a = 0, b = 1, c = 0, temp;
    n = __VERIFIER_nondet_int();
    if (!(n <= SIZE)) {
        return 0;
    }

    int threshold = 0;
    while (threshold < n) {
        assume_abort_if_not(b > 0); // Ensure no division by zero

        // Generate a sequence with defined properties
        if (threshold % 3 == 0) {
            temp = a;
            a = b;
            b = temp;
        } else if (threshold % 2 == 0) {
            c = a + b;
        } else {
            int diff = a - b;
            if (diff < 0) {
                diff = -diff; // Get the absolute value
            }
            c = diff;
        }

        // Check a relation maintained throughout
        __VERIFIER_assert(a + b + c > 0);

        threshold++;
    }

    printf("Completed: a=%u, b=%u, c=%u\n", a, b, c);

    return 0;
}