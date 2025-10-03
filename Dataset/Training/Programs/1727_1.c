#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

#define MAX_LENGTH 100

int main() {
    int length = __VERIFIER_nondet_int();
    if (length <= 0 || length > MAX_LENGTH) {
        return 0;
    }

    int *array = malloc(sizeof(int) * length);
    int i, sum = 0, count_of_neg = 0;

    for (i = 0; i < length; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    for (i = 0; i < length; i++) {
        sum += array[i];
        if (array[i] < 0) {
            count_of_neg++;
        }
    }

    printf("Sum: %d\n", sum);
    printf("Negative Count: %d\n", count_of_neg);

    // Ensure that the count of negative numbers is less than or equal to length
    __VERIFIER_assert(count_of_neg <= length);

    free(array);
    return 0;
}