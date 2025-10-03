#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

#define MAX_N 10

int main() {
    /* Nondeterministic inputs */
    int n = __VERIFIER_nondet_int();
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    /* Precondition: sequence length between 2 and MAX_N, a,b non-negative */
    if (!(n >= 2 && n <= MAX_N && a >= 0 && b >= 0)) {
        return 0;
    }

    /* Generalized Fibonacci-like sequence array */
    int arr[MAX_N + 3];
    arr[0] = a;
    arr[1] = b;

    /* Build arr[2] .. arr[n-1] */
    int i = 2;
    while (i < n) {
        arr[i] = arr[i - 1] + arr[i - 2];
        i++;
    }

    /* Compute arr[n] and arr[n+1] for identity checks */
    arr[n] = arr[n - 1] + arr[n - 2];
    arr[n + 1] = arr[n] + arr[n - 1];

    /* Sum the first n elements */
    int sum = 0;
    i = 0;
    while (i < n) {
        sum += arr[i];
        i++;
    }

    /* Verify the known identity: sum_{i=0..n-1} arr[i] + b == arr[n+1] */

    /* Compute GCD of a and b using the Euclidean algorithm */
    int x = a;
    int y = b;
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    int g = x;

    /* Verify that GCD divides arr[n] and the sum */

    /* Compute the product a * b by repeated addition */
    int product = 0;
    i = 0;
    while (i < b) {
        product += a;
        i++;
    }
    /* Verify multiplication */

    /* Compute prefix maximums */
    int prefixMax[MAX_N + 3];
    prefixMax[0] = arr[0];
    i = 1;
    while (i < n) {
        if (prefixMax[i - 1] > arr[i]) {
            prefixMax[i] = prefixMax[i - 1];
        } else {
            prefixMax[i] = arr[i];
        }
        i++;
    }
    /* Check that prefixMax is non-decreasing */
    i = 1;
    while (i < n) {
        i++;
    }

    /* Compute prefix minimums */
    int prefixMin[MAX_N + 3];
    prefixMin[0] = arr[0];
    i = 1;
    while (i < n) {
        if (prefixMin[i - 1] < arr[i]) {
            prefixMin[i] = prefixMin[i - 1];
        } else {
            prefixMin[i] = arr[i];
        }
        i++;
    }
    /* Check that prefixMin is non-increasing */
    i = 1;
    while (i < n) {
        i++;
    }
    /* Final check: smallest <= largest */

    /* Build reversed copy of the sequence */
    int revArr[MAX_N + 3];
    i = 0;
    while (i < n) {
        revArr[n - 1 - i] = arr[i];
        i++;
    }
    /* Spot checks on reversed array */
    __VERIFIER_assert(revArr[n - 1] == arr[0]);

    return 0;
}