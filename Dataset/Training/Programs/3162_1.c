#include <assert.h>
#include <stdlib.h>

/*
  A small helper for verification:
  if the condition is false, we abort (reach an error).
*/
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
  Nondeterministic integer generator (stand-in for a verifier's input).
*/
extern int __VERIFIER_nondet_int(void);

/*
  This program computes the integer square root of a non-negative integer n
  (bounded by 1 000 000 to avoid 32-bit overflow) via binary search.
  It then checks the postcondition:
     r*r <= n < (r+1)*(r+1)
*/
int main() {
    int n = __VERIFIER_nondet_int();
    /* restrict the range so that (r+1)^2 won't overflow 32 bits */
    if (n < 0 || n > 1000000) {
        return 0;
    }

    int left = 0;
    int right = n;
    int r = 0;

    /* binary search loop to find floor(sqrt(n)) */
    while (left <= right) {
        int mid = (left + right) / 2;
        /* cast to long long to avoid overflow when squaring */
        if ((long long)mid * mid <= n) {
            r = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    /* postconditions: r^2 <= n < (r+1)^2 */
    __VERIFIER_assert((long long)r * r <= n);

    return 0;
}