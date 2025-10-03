#include <limits.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "new_program.c", 5, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);

int main(void) {
    int N = __VERIFIER_nondet_int();
    if (N <= 0 || N > 1024) {
        return 1;
    }

    int *array = malloc(N * sizeof(int));
    if (!array) {
        return 1; // Failed to allocate memory
    }

    int i;
    int even_count = 0;

    // Fill the array with alternating even and odd numbers starting from 0
    for (i = 0; i < N; i++) {
        array[i] = i;
        if (array[i] % 2 == 0) {
            even_count++;
        }
    }

    // Verify the count of even numbers is half of N if N is even, or (N-1)/2 + 1 if N is odd
    int expected_even_count = (N % 2 == 0) ? N / 2 : (N / 2) + 1;
    __VERIFIER_assert(even_count == expected_even_count);

    free(array);
    return 0;
}