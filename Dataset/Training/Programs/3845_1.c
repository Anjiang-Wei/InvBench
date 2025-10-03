#include <stdio.h>
#include <stdlib.h>

void reach_error() {
    printf("Error reached\n");
    exit(1);
}
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
    return;
}

int main() {
    int n1, n2, max1, max2;
    long long sum1 = 0, sum2 = 0;
    n1 = __VERIFIER_nondet_int();
    n2 = __VERIFIER_nondet_int();

    assume_abort_if_not(n1 >= 0 && n1 <= 100);
    assume_abort_if_not(n2 >= 0 && n2 <= 100);

    max1 = 0;
    max2 = 0;

    for (int i = 0; i < n1; i++) {
        max1 = i * 2 + 1;
        sum1 += max1;
    }

    for (int j = 0; j < n2; j++) {
        max2 = j * 3 + 2;
        sum2 += max2;
    }

    // Calculate combined max and sum
    int combined_max = (max1 > max2) ? max1 : max2;
    long long combined_sum = sum1 + sum2;

    // Assertions
    __VERIFIER_assert(combined_max >= 0);

    return 0;
}