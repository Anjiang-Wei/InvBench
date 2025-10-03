#include <assert.h>
#include <stdlib.h>

// Function used to trigger an error
void reach_error(void) {
    assert(0);
}

// Mock nondeterministic integer
int __VERIFIER_nondet_int(void) {
    return rand() % 20 - 10; // Mock implementation
}

// Mock nondeterministic boolean
_Bool __VERIFIER_nondet_bool(void) {
    return rand() % 2 == 0; // Mock implementation
}

// Verification assertion function
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// Compute a simple length transformation process on a string
int main() {
    int length = __VERIFIER_nondet_int();
    if (length < 0) {
        return 0;
    }

    int i;
    char str[50];
    for (i = 0; i < length && i < 49; i++) {
        str[i] = 'A' + (i % 26); // Fill with letters of the alphabet
    }
    str[i] = '\0'; // Null-terminate the string

    int transformed_length = 0;

    // Simulate a transformation on the string length
    for (i = 0; i < length; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            transformed_length += 1;
        }
    }

    // Post-condition: The transformed length should be less than or equal to the original length
    __VERIFIER_assert(transformed_length <= length);

    return 0;
}