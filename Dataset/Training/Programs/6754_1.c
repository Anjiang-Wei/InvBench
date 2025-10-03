#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/* div.cfg:
   names=dividend divisor quotient remainder orig
   precondition=dividend>=0 && divisor>0
   loopcondition=dividend>=divisor
   loop=dividend-=divisor; quotient++;
   postcondition=(0 <= remainder && remainder < divisor) &&
                 (orig == quotient*divisor + remainder)
   learners=conj
*/

int main() {
    int dividend = __VERIFIER_nondet_int();
    int divisor = __VERIFIER_nondet_int();
    /* require non-negative dividend and positive divisor */
    if (!(dividend >= 0 && divisor > 0)) {
        return 0;
    }

    int orig = dividend;
    int quotient = 0;
    int remainder;

    /* repeatedly subtract divisor */
    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }
    remainder = dividend;

    /* verify the standard division relation */
    __VERIFIER_assert(remainder >= 0);

    return 0;
}