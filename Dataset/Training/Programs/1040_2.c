#include <assert.h>
#include <stdio.h>

extern void abort(void);
void reach_error() { assert(0); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int __VERIFIER_nondet_int(void) {
    int random_value;
    scanf("%d", &random_value);
    return random_value;
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int main() {
    int n, sum = 0, i, factorial = 1, temp_sum = 0, temp_factorial = 1;

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= 10);

    for (i = 1; i <= n; i++) {
        sum += i;
        factorial *= i;
    }

    while (1) {
        if (temp_sum >= sum || temp_factorial >= factorial) {
            break;
        }
        temp_sum++;
        temp_factorial *= temp_sum;
    }

    __VERIFIER_assert(temp_sum <= sum);

    printf("Sum: %d, Factorial: %d\n", sum, factorial);
    printf("Temp Sum: %d, Temp Factorial: %d\n", temp_sum, temp_factorial);

    return 0;
}