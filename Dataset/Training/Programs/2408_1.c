#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "proposed.c", 5, "reach_error");
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
extern _Bool __VERIFIER_nondet_bool(void);

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (a < 0 || b < 0) {
        return 0;
    }

    int sum = 0;
    int count = 0;

    // Loop that runs until sum exceeds a certain threshold
    // Here we ensure that it is meaningful and interesting
    while (sum < 1000 && count < 100) {
        _Bool add_a = __VERIFIER_nondet_bool();

        if (add_a) {
            sum += a;
        } else {
            sum += b;
        }

        count++;
    }

    // Check conditions after the loop
    __VERIFIER_assert(count <= 100);

    // Log the results (not part of verification, just for completeness)
    printf("Final sum: %d\n", sum);
    printf("Number of iterations: %d\n", count);

    return 0;
}