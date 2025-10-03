#include <assert.h>
void reach_error(void) { assert(0); }

// Mock functions provided by verification tools
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Logical pattern:
names= a b c
precondition= a >= 0 && b > a && c > 0
loopcondition= c > 0
loop= if (a < b) a += c; c--;
postcondition= (a >= b) || (c == 0)
learners= linear functions with modulo operation
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();

    if (!(a >= 0 && b > a && c > 0)) {
        return 0;
    }

    while (c > 0) {
        if (a < b) {
            a = (a + c) % b; // Emphasizing modular behavior as part of the logic
        }
        c--;
    }

    __VERIFIER_assert((a >= b) || (c == 0));

    return 0;
}