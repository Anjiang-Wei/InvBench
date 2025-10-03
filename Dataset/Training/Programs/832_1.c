#include <assert.h>
#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);

void reach_error() { assert(0); }

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

int *generate_array(int n, int increment) {
    int *array = malloc(n * sizeof(*array));
    if (n > 0) {
        array[0] = increment;
        for (int i = 1; i < n; i++) {
            array[i] = array[i - 1] + increment;
        }
    }
    return array;
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000);

    int increment_a = 3;
    int increment_b = 5;

    int *a = generate_array(N, increment_a);
    int *b = generate_array(N, increment_b);

    for (int i = 0; i < N; i++) {
        a[i] += b[i];
    }

    // Verify that all elements in `a` are divisible by the gcd of increment_a and increment_b
    int gcd = 1;
    for (int i = 2; i <= increment_a && i <= increment_b; i++) {
        if (increment_a % i == 0 && increment_b % i == 0) {
            gcd = i;
        }
    }

    for (int i = 0; i < N; i++) {
        __VERIFIER_assert(a[i] % gcd == 0);
    }

    free(a);
    free(b);

    return 0;
}