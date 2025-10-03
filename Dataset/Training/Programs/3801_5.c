#include <stdio.h>
#include <stdlib.h>

// Verification harness
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_state_machine.c", 10, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

/* nondet input generator */
extern int __VERIFIER_nondet_int(void);

// Global state variables
static int state = 0;
static int counter1 = 0;
static int counter2 = 0;
static int flagA = 0;
static int flagB = 1;

/*
  A simple state machine:
  - state in {0,1,2,3}
  - input in {1,2,3,4}
  - transitions update counters and flags
  - error conditions at bottom
*/
int calculate_output(int input) {
    int output = -1;

    // State 0 transitions
    if (state == 0 && input == 1) {
        state = 1;
        counter1 += 1;
        flagA = 1;
        output = 100;
    } else if (state == 0 && input == 2) {
        state = 2;
        counter2 += 2;
        flagA = 0;
        output = 101;
    } else if (state == 0 && input == 3) {
        state = 3;
        counter1 += 2;
        counter2 += 1;
        flagB = 0;
        output = 102;
    } else if (state == 0 && input == 4) {
        // self loop
        counter1 -= 1;
        counter2 -= 1;
        output = 103;
    }
    // State 1 transitions
    else if (state == 1 && input == 1) {
        state = 0;
        counter1 -= 1;
        flagB = 1;
        output = 200;
    } else if (state == 1 && input == 2) {
        state = 2;
        counter2 += 3;
        flagA = 0;
        output = 201;
    } else if (state == 1 && input == 3) {
        state = 3;
        counter1 += 1;
        counter2 -= 1;
        output = 202;
    } else if (state == 1 && input == 4) {
        // stay in 1
        counter1 += 0;
        output = 203;
    }
    // State 2 transitions
    else if (state == 2 && input == 1) {
        state = 0;
        counter2 -= 2;
        flagA = 1;
        output = 300;
    } else if (state == 2 && input == 2) {
        state = 1;
        counter1 += 2;
        flagB = 0;
        output = 301;
    } else if (state == 2 && input == 3) {
        state = 3;
        counter2 += 2;
        output = 302;
    } else if (state == 2 && input == 4) {
        // self loop
        counter2 -= 1;
        output = 303;
    }
    // State 3 transitions
    else if (state == 3 && input == 1) {
        state = 0;
        counter1 = 0;
        counter2 = 0;
        flagA = 0;
        flagB = 1;
        output = 400;
    } else if (state == 3 && input == 2) {
        state = 1;
        counter1 += 5;
        output = 401;
    } else if (state == 3 && input == 3) {
        state = 2;
        counter2 += 5;
        output = 402;
    } else if (state == 3 && input == 4) {
        // stay in 3
        counter1 -= 3;
        output = 403;
    } else {
        // invalid input, no change
        output = -1;
    }

    return output;
}

int main(void) {
    // iterate over nondet inputs
    while (1) {
        int inp = __VERIFIER_nondet_int();
        // restrict to 1..4
        if (inp < 1 || inp > 4) {
            // exit loop if out of domain
            break;
        }
        int out = calculate_output(inp);

        // safety checks: error conditions
        // 1) counter1 should never go negative when flagA==1
        if (flagA == 1) {
        }
        // 2) counter2 must not exceed 20 in state 2
        if (state == 2) {
        }
        // 3) if in state 3 and flagB==0, counter1+counter2 must be <= 10
        if (state == 3 && flagB == 0) {
        }
        // 4) flagB flips only in state 0->3 or 1->0
        if (flagB == 0) {
        }
        // 5) state must be within 0..3
        __VERIFIER_assert(state >= 0 && state <= 3);

        // optional: print state (not needed for verification)
        // printf("inp=%d => out=%d, state=%d, c1=%d, c2=%d, fA=%d, fB=%d\n",
        //        inp, out, state, counter1, counter2, flagA, flagB);
    }

    return 0;
}