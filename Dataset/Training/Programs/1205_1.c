#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Example program: Balanced Increment-Decrement
 * variables: a, b, c
 * precondition: a >= 0 && b >= 0 && c == 0
 * loopcondition: a > 0 || b > 0
 * loopbody: (if a > b, a--; else if b > 0, b--);
 * postcondition: c == (initial_a + initial_b)
 */

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = 0;
    if (!(a >= 0 && b >= 0 && c == 0)) {
        return 0;
    }

    int initial_a = a;
    int initial_b = b;

    while (a > 0 || b > 0) {
        if (a > b) {
            a--;
        } else if (b > 0) {
            b--;
        }
        c++;
    }

    __VERIFIER_assert(c == initial_a + initial_b);
    return 0;
}