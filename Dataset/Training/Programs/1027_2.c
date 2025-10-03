#include <assert.h>
#include <stdbool.h>

void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int t = 0;

    if (!(a > 0 && b > 0)) {
        return 0;
    }

    while (__VERIFIER_nondet_bool()) {
        int diff = a - b;

        if (diff > 0) {
            a--;
        } else {
            b--;
        }

        t += sum_of_digits(a) + sum_of_digits(b);

        // Ensure t is always non-negative and both a, b remain non-negative
    }

    // Assurance of constraints at loop's end
    __VERIFIER_assert(a * b >= 0);

    return 0;
}