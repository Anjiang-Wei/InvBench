#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= 1000);

    int *a = malloc(sizeof(int) * n);
    assume_abort_if_not(a != NULL);

    int target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 0 && target <= 1000);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        a[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(a[i] >= 0 && a[i] <= 10); // Assuming a[i] values between 0 and 10
        sum += a[i];
        if (sum > target) {
            break;
        }
    }

    __VERIFIER_assert(sum <= (n * 10) && sum >= 0);

    // Ensures that if the sum stops because of exceeding target, the condition is checked
    if (sum > target) {
    }

    free(a);
    return 0;
}