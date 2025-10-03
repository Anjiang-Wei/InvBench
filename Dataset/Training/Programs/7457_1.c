#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_verifier_program.c", 5, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

extern int __VERIFIER_nondet_int();

#define MAX_INT (2147483647)

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N < MAX_INT / sizeof(int));

    int *array = malloc(N * sizeof(int));
    if (array == NULL) {
        return 1; // Memory allocation failed
    }

    // Fill the array with non-deterministic integers
    for (int i = 0; i < N; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate sum and check for integer overflow using assertions
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        assume_abort_if_not(sum + array[i] >= sum); // Ensure no integer overflow
        sum += array[i];
    }

    // Set first element to the calculated sum
    array[0] = sum;

    // A loop condition based on the content of the array
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (array[i] < sum) {
            cnt++;
        }
    }

    // Verify the count is less than N
    __VERIFIER_assert(cnt < N);

    // Cleanup
    free(array);
    return 0;
}