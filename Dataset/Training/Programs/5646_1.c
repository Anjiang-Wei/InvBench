#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 9, "reach_error"); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}
extern int __VERIFIER_nondet_int(void);
void *malloc(size_t size);

#define SIZE 10000

int main() {
    int n, i, sum;
    int *array = malloc(sizeof(int) * SIZE);

    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 1 && n <= SIZE);

    // Initialize the array with random values
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        array[i] = rand() % 100;
    }

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += array[i];
    }

    int average = sum / n;

    int count_below_avg = 0;
    for (i = 0; i < n; i++) {
        if (array[i] < average) {
            count_below_avg++;
        }
    }

    __VERIFIER_assert(count_below_avg <= n);

    free(array);
    return 0;
}