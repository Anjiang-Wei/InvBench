#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

#define N 10

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int compute_sum(int *array, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

int main() {
    int input[N];
    int target_sum = 0;
    int iteration = 0;

    // Initialize the input array with non-deterministic values
    for (int i = 0; i < N; i++) {
        input[i] = __VERIFIER_nondet_int();
    }

    // Loop with a computation and condition check
    while (iteration < N) {
        int current_sum = compute_sum(input, N);

        // Check if the current sum is even or odd
        if (current_sum % 2 == 0) {
            target_sum += current_sum / 2;
        } else {
            target_sum += (current_sum + 1) / 2;
        }
    }

    // Final assertion check
    __VERIFIER_assert(target_sum >= 0);

    printf("Final target sum: %d\n", target_sum);
    return 0;
}