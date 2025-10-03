#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
 * New Program Specification:
 * names=x y counter sum
 * precondition=x==0 && y==0 && counter==0 && sum==0
 * loopcondition=counter < 50
 * loop= x += 2; y += x; sum += y; counter++;
 * postcondition=sum > 0
 */
int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int counter = __VERIFIER_nondet_int();
    int sum = __VERIFIER_nondet_int();

    if (!(x == 0 && y == 0 && counter == 0 && sum == 0)) {
        return 0;
    }

    while (counter < 50) {
        x += 2;    // Increment x by 2 each iteration
        y += x;    // Increment y by the current x
        sum += y;  // Add the current y to sum
        counter++; // Increment the counter
    }

    // Ensure that the sum is positive after the loop
    __VERIFIER_assert(sum > 0);

    return 0;
}