#include <assert.h>
void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

/*
Algorithm:
names=x y max
precondition=x >= 0 && y >= 0
loopcondition=x > 0 && y < max
loop=x--; y++;
postcondition=x == 0 || y == max
*/

int main() {
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int max = __VERIFIER_nondet_int();

    // Pre-condition
    if (!(x >= 0 && y >= 0)) {
        return 0;
    }

    // Ensure max is greater than y for initialization
    if (max <= y) {
        return 0;
    }

    // Loop
    while (x > 0 && y < max) {
        x--; // Decrement x towards zero
        y++; // Increment y towards max
    }

    // Post-condition
    __VERIFIER_assert(x == 0 || y == max);
    return 0;
}