#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "verifier.c", 5, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int size = __VERIFIER_nondet_int();
    if (size <= 0) {
        return 1;
    }

    int *numbers = malloc(sizeof(int) * size);
    if (numbers == NULL) {
        return 1;
    }

    // Initialize array with values
    for (int i = 0; i < size; i++) {
        numbers[i] = __VERIFIER_nondet_int();
    }

    int sumPositive = 0;
    int productNegative = 1;

    // Process the numbers
    for (int i = 0; i < size; i++) {
        if (numbers[i] > 0) {
            sumPositive += numbers[i];
        } else if (numbers[i] < 0) {
            productNegative *= numbers[i];
        }
    }

    // Verify condition (an example condition here is just checking forms; real one would be more specific)
    _Bool condition = productNegative != 0 || sumPositive > 0;
    __VERIFIER_assert(condition);

    free(numbers);
    return 0;
}