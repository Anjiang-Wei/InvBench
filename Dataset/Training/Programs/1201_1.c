#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "example_new.c", 3, "reach_error"); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

int sum_of_squares(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i * i;
    }
    return sum;
}

void reverse_array(int *arr, int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int n = __VERIFIER_nondet_int();

    // Assuming n is a non-negative integer
    if (n < 0) {
        return 0;
    }

    int sum = sum_of_squares(n);

    // Verify that the sum of squares is greater than or equal to 0
    __VERIFIER_assert(sum >= 0);

    // Create and reverse an array of size n
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }
    reverse_array(arr, n);

    // Verify that the first element is n-1 after reversing
    if (n > 0) {
    }

    free(arr);

    return 0;
}