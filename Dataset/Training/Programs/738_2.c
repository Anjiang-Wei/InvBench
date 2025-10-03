#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "complex.c", 10, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern void abort(void);

// Custom assert function
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Helper function for safe array access
int safe_access(int *arr, unsigned int index, unsigned int size) {
    if (index < size) {
        return arr[index];
    }
    return 0; // or some safe fallback value
}

int main() {
    unsigned int SIZE = 5;
    int buffer[SIZE];
    unsigned int i;

    for (i = 0; i < SIZE; i++) {
        buffer[i] = __VERIFIER_nondet_int();
    }

    int sum_of_squares = 0;
    int potential_error = 0;
    unsigned int counter = 0;

    while (counter < 15) { // Ensuring loop runs a limited number of times.
        unsigned int idx = __VERIFIER_nondet_int();

        int value = safe_access(buffer, idx, SIZE);
        sum_of_squares += value * value;

        potential_error += value - idx;

        // Just incrementally move forward to prevent infinite loop
        counter++;
    }

    __VERIFIER_assert(sum_of_squares >= 0);

    return 0;
}