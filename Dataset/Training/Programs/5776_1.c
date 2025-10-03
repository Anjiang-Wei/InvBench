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
   This program simulates a process that increments a counter up to a boundary condition
   while maintaining a related variable that represents some dependent state.
   It aims to ensure that when the loop exits, certain conditions hold true, which can be
   checked by a verification tool.
*/

int main() {
    int counter = __VERIFIER_nondet_int();
    int state = __VERIFIER_nondet_int();

    // Initial conditions
    if (!(counter >= 0 && counter <= 10 && state == counter * 2)) {
        return 0;
    }

    // The loop modifies state in relation to counter
    while (counter < 20) {
        state = state + (counter * 2);
        counter++;
    }

    // Conditions to check after the loop's termination
    __VERIFIER_assert(state <= 400 && counter == 20);

    return 0;
}