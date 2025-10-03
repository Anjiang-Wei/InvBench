#include <assert.h>
#include <stdbool.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
This program aims to sum a sequence of positive integers
and store the sum in a variable 'sum'. It stops when a
non-positive integer is encountered or when we reach a
maximum iteration count. The verification condition ensures
that the sum is always non-negative.
*/
int main() {
    int sum = 0;
    int counter = 0;
    int max_iters = 100; // prevent infinite loop for safety

    while (counter < max_iters) {
        int num = __VERIFIER_nondet_int();
        if (num <= 0) {
            break;
        }
        sum += num;
        counter++;
    }

    __VERIFIER_assert(sum >= 0);
    return 0;
}