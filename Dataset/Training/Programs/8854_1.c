#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  Program to verify a simple linear search algorithm ensuring that all elements
  before a found position are not the search target.
*/
int main() {
    int n = __VERIFIER_nondet_int();      // size of the array (non-deterministic)
    int target = __VERIFIER_nondet_int(); // the target value to search for
    int found = -1;                       // variable to store the index of the found target

    // Ensure n is positive for the purpose of this example
    if (n <= 0) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int(); // fill array with non-deterministic values
    }

    // Simple linear search loop
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            found = i;
            break;
        }
    }

    // Verification condition: The index where target is found must be the first such occurrence.
    if (found != -1) {
        for (int j = 0; j < found; j++) {
            __VERIFIER_assert(arr[j] != target);
        }
    }

    return 0;
}