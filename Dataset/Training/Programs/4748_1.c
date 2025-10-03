#include <assert.h>
#include <limits.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error(void) { assert(0); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int is_even(int n) {
    return n % 2 == 0;
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && b > 0);

    int sum = 0;
    int counter = 0;

    while (counter < b) {
        sum += a;

        if (is_even(counter)) {
            a++;
        } else {
            a--;
        }

        counter++;
    }

    __VERIFIER_assert(sum >= 0); // Ensure the sum is non-negative
    return 0;
}