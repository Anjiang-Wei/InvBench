#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached\n");
    abort();
}

#define ARRAY_SIZE 100

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

extern int __VERIFIER_nondet_int(void);
extern unsigned int __VERIFIER_nondet_uint(void);

void process(int *arr, int N) {
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        arr[i] = __VERIFIER_nondet_int();
        if (arr[i] < 0) {
            arr[i] = 0;
        }
        sum += arr[i];
    }

    int average = (N > 0) ? (sum / N) : 0;

    int countAboveAverage = 0;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > average) {
            countAboveAverage++;
        }
    }

    __VERIFIER_assert(countAboveAverage <= N);
}

int main() {
    int N = __VERIFIER_nondet_uint();
    if (N <= 0 || N > ARRAY_SIZE) {
        return 0;
    }

    int arr[ARRAY_SIZE];

    // Function to process the array
    process(arr, N);

    return 0;
}