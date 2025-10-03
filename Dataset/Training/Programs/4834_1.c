#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Description:
   This program attempts to ensure that in a list of numbers, all elements
   are sorted in non-decreasing order using a simple comparison and swap
   algorithm. The properties of the program will help a verification tool
   ensure the correctness of the sorting logic.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int d = __VERIFIER_nondet_int();

    // Precondition: The numbers are not necessarily sorted
    if (__VERIFIER_nondet_bool()) {
        return 0; // Non-deterministic path to exit early
    }

    // A simple sorting logic (Bubble Sort-like) designed to illustrate useful properties
    int array[4] = {a, b, c, d};
    int sorted = 0;

    while (!sorted) {
        sorted = 1; // Assume sorted unless we find a reason to swap
        for (int i = 0; i < 3; ++i) {
            if (array[i] > array[i + 1]) {
                // Swap the elements
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                sorted = 0; // If we had to swap, then the array wasn't sorted
            }
        }
    }

    // Postcondition: Array is sorted in non-decreasing order
    __VERIFIER_assert(array[0] <= array[1]);

    return 0;
}