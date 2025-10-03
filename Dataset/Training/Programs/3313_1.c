#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Inspired pattern:
names=a b sum
precondition=a>=0 && b>=0
loopcondition=(a>0) || (b>0)
loop= if (a > 0) a = a - 1; else if (b > 0) b = b - 1; sum = sum + 1;
postcondition= sum == initial_a + initial_b
learners= linear
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    if (!(a >= 0 && b >= 0)) {
        return 0;
    }

    int initial_a = a;
    int initial_b = b;
    int sum = 0;

    while ((a > 0) || (b > 0)) {
        if (a > 0) {
            a = a - 1;
        } else if (b > 0) {
            b = b - 1;
        }
        sum = sum + 1;
    }

    __VERIFIER_assert(sum == initial_a + initial_b);
    return 0;
}