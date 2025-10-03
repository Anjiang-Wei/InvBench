#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}
extern unsigned int __VERIFIER_nondet_uint(void);

int main() {
    unsigned int a = __VERIFIER_nondet_uint();
    unsigned int b = __VERIFIER_nondet_uint();
    unsigned int sum = 0;
    unsigned int count = 0;

    // Apply a constraint to avoid overflow
    if (a > 1000) {
        a = 1000;
    }
    if (b > 1000) {
        b = 1000;
    }

    while (count < 100 && a < b) {
        if (a % 2 == 0) {
            sum += a;
        }
        a++;
        count++;
    }

    __VERIFIER_assert(sum % 2 == 0);

    printf("Final sum of even numbers: %u\n", sum);
    return 0;
}