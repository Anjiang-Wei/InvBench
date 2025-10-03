#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* Custom.cfg:
names=a b c target
beforeloop=
beforeloopinit=
precondition=a==0 && b==0 && target>0 && c==0
loopcondition=a<target
loop=a++; b=b+1; if(a % 2 == 0) { c++; }
postcondition=c==b/2
afterloop=
learners= conj
*/
int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int target = __VERIFIER_nondet_int();

    // Precondition setup
    if (!(a == 0 && b == 0 && target > 0 && c == 0)) {
        return 0;
    }

    // Increment a and b, increment c if a is even
    while (a < target) {
        a++;
        b++;
        if (a % 2 == 0) {
            c++;
        }
    }

    // Postcondition verification
    // c should be equal to b divided by 2 since only half of b's increments are even numbers
    __VERIFIER_assert(c == b / 2);

    return 0;
}