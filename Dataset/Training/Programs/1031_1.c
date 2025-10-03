#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int process_command(int state, int command) {
    if (state == 0) {
        if (command == 1) {
            return 1;
        }
        if (command == 2) {
            return 2;
        }
    } else if (state == 1) {
        if (command == 2) {
            return 3;
        }
        if (command == 3) {
            return 0;
        }
    } else if (state == 2) {
        if (command == 1) {
            return 3;
        }
        if (command == 3) {
            return 1;
        }
    } else if (state == 3) {
        if (command == 1) {
            return 0;
        }
        if (command == 2) {
            return 2;
        }
    }
    return state; // no change for unrecognized command
}

int main() {
    int state = 0; // initial state
    int command;
    int counter = 0;

    while (1) {
        command = __VERIFIER_nondet_int();
        assume_abort_if_not(command >= 1 && command <= 3); // command must be 1, 2, or 3

        state = process_command(state, command);

        counter++;
        if (counter > 1000) {
            break; // prevent infinite loop in verification
        }

        // Assert that certain conditions hold
        __VERIFIER_assert(state >= 0 && state <= 3); // state should always be valid
    }

    return 0;
}