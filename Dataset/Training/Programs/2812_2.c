#include <assert.h>
#include <stdbool.h>

void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* New Algorithm:
names= a b count
precondition= a > 0 && b > 0
beforeloop= count = 0;
loopcondition= b != 0
loop= int temp = b; b = a % b; a = temp; count++;
postcondition= a > 0 && (count > 0 || b == 0)
learners= linear
*/
int gcd(int a, int b) {
    int count = 0;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
        count++;
    }
    return a;
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();

    if (!(a > 0 && b > 0)) {
        return 0;
    }

    int result = gcd(a, b);

    // Postcondition: The return value should be greater than 0 because
    // gcd for positive numbers is at least 1.

    // The gcd of a number and itself is the number
    if (a == b) {
        __VERIFIER_assert(result == a);
    }

    return 0;
}