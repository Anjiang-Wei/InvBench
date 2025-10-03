#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sum_cubes.c", 3, "reach_error"); }

extern short __VERIFIER_nondet_short(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int counter = 0;
int main() {
    short k;
    long long c, r, cube_sum;

    /* nondeterministic bound for loop: 0 <= k <= 100 */
    k = __VERIFIER_nondet_short();
    assume_abort_if_not(k >= 0 && k <= 100);

    /*
       We compute:
         r = 1 + 2 + ... + c
         cube_sum = 1^3 + 2^3 + ... + c^3
       And we check the identity:
         (1 + 2 + ... + c)^2 == 1^3 + 2^3 + ... + c^3
    */

    c = 0;
    r = 0;
    cube_sum = 0;

    while (counter++ < 100) {
        /* check the sum-of-cubes identity at each iteration */

        if (!(c < k)) {
            break;
        }

        /* advance the sequence */
        c = c + 1;
        r = r + c;
        cube_sum = cube_sum + c * c * c;
    }

    /* final check of the identity */
    __VERIFIER_assert(r * r - cube_sum == 0);

    return 0;
}