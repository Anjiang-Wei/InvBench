#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Program Description:
   This program initializes two integers, `a` and `b`.
   It ensures that the precondition `a >= 1 && b >= 1` holds true.
   The loop will increment both integers while maintaining the condition for `a+b` below a specific bound.
   The program checks a meaningful postcondition to ensure `a * b` remains within logical constraints.
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    // Precondition: ensure a and b start with realistic values for this scenario
    if (!(a >= 1 && b >= 1)) {
        return 0;
    }

    while (a + b < 10) {
        if (__VERIFIER_nondet_bool()) {
            a++;
        } else {
            b++;
        }
    }

    // Postcondition: to ensure some meaningful property of a and b
    __VERIFIER_assert(a * b >= 4);
    return 0;
}