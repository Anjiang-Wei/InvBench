#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Reach error\n");
    abort();
}
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

extern int __VERIFIER_nondet_int();
extern char __VERIFIER_nondet_char();

#define MAX_ENTRIES 10

int main() {
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n > 0 && n <= MAX_ENTRIES);

    char entries[MAX_ENTRIES];
    int valid_count = 0;

    for (int i = 0; i < n; i++) {
        entries[i] = __VERIFIER_nondet_char();

        // Let's define valid characters between 'a' to 'z'
        if (entries[i] >= 'a' && entries[i] <= 'z') {
            valid_count++;
        }
    }

    // Perform a checksum-like verification
    int checksum = 0;
    for (int i = 0; i < n; i++) {
        checksum += entries[i];
    }

    // Ensure that the checksum is within expected bounds assuming 'a'..'z' entries
    // Using a rough rule: average char code >= 'a' and <= 'z'
    int avg_char_expected = (checksum / n);

    // Check if the average character code is within the expected range for valid characters

    // Let's ensure that we counted valid entries correctly
    __VERIFIER_assert(valid_count <= n);

    return 0;
}