#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int __VERIFIER_nondet_int();

int main() {
    int n = __VERIFIER_nondet_int();
    if (n < 5 || n > 100) {
        return 0;
    }

    int *array = malloc(sizeof(int) * n);
    assume_abort_if_not(array != NULL);

    int i;
    int even_count = 0;
    int odd_count = 0;

    for (i = 0; i < n; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    for (i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    int total_count = even_count + odd_count;
    __VERIFIER_assert(total_count == n);

    // For demonstration, print the results
    printf("Even Count: %d, Odd Count: %d, Total: %d\n", even_count, odd_count, total_count);

    free(array);
    return 0;
}