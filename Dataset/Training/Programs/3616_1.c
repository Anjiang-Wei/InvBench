#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

#define MAX_SIZE 1000

int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int size = __VERIFIER_nondet_int();
    if (size <= 0 || size > MAX_SIZE) {
        return 0;
    }

    int *array = malloc(sizeof(int) * size);
    if (array == NULL) {
        return 0; // Memory allocation failed
    }

    for (int i = 0; i < size; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    int prime_count = 0;
    for (int i = 0; i < size; i++) {
        if (is_prime(array[i])) {
            prime_count++;
        }
    }

    // Ensure that prime_count does not exceed size
    __VERIFIER_assert(prime_count <= size);

    free(array);

    return 0;
}