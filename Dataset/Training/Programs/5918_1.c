#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "state_machine.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

typedef struct {
    int state; // State variable
    int count; // Counter for events
} StateMachine;

// Transition function for the state machine
void transition(StateMachine *sm, int event) {
    switch (sm->state) {
    case 0:
        if (event == 1) {
            sm->state = 1;
        }
        break;
    case 1:
        if (event == 2) {
            sm->state = 2;
        }
        break;
    case 2:
        if (event == 1) {
            sm->state = 0;
        }
        break;
    default:
        reach_error(); // Should never reach this
        break;
    }
    sm->count++;
}

int main() {
    StateMachine sm;
    sm.state = 0;
    sm.count = 0;

    int max_events = __VERIFIER_nondet_int();
    assume_abort_if_not(max_events > 0 && max_events <= 10);

    int i;
    for (i = 0; i < max_events; i++) {
        int event = __VERIFIER_nondet_int();
        assume_abort_if_not(event == 1 || event == 2);
        transition(&sm, event);

        // Simple property: The counter should not exceed max_events
        __VERIFIER_assert(sm.count <= max_events);

        // Ensure the state is always valid (0, 1, or 2)
    }

    printf("Final State: %d\n", sm.state);
    printf("Event Count: %d\n", sm.count);

    return 0;
}