#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New program structure:
names=p q arr n
precondition= (p==0) && (n>0)
loopcondition= p<n && n<10
loop=p++; q--;
postcondition= arr[n-1] == 1
*/
int main() {
    int p = __VERIFIER_nondet_int();
    int q = __VERIFIER_nondet_int();
    int n = __VERIFIER_nondet_int();

    if (!((p == 0) && (n > 0))) {
        return 0; // Ensure initial conditions are met
    }

    // Assume n is restricted between 1 and 9 to ensure finite simulation
    if (n >= 10) {
        return 0;
    }

    int arr[10] = {0}; // Initialize an array of 0s

    q = n;

    // Fill the array with 1s while decrementing q
    while (p < n && q > 0) {
        arr[p] = 1;
        p++;
        q--;
    }

    // Verification: check that the last index set (n-1) is 1
    __VERIFIER_assert(arr[n - 1] == 1);

    return 0;
}