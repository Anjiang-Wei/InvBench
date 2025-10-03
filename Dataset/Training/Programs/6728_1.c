#include <assert.h>
#include <stdbool.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Simple bounded sum with constraints:
names=a b sum
precondition=0<=a<=10 && 0<=b<=10
loopcondition=b>0
loop= sum += a;
postcondition=sum == a*b
*/

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int sum = 0;

    // Precondition constraints
    if (a < 0 || a > 10 || b < 0 || b > 10) {
        return 0;
    }

    int temp_b = b;

    while (temp_b > 0) {
        sum += a;
        temp_b--;
    }

    // Check postcondition
    __VERIFIER_assert(sum == a * b);

    return 0;
}