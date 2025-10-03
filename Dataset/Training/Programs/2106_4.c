// Elevator control simulation for verification
// This program reads commands nondeterministically and models
// an elevator moving between floors 0 and 5 with door operations.
// Safety properties are checked via __VERIFIER_assert and reach_error.

#include <stdio.h>
#include <stdlib.h>

// Prototype for nondeterministic input
extern int __VERIFIER_nondet_int(void);
// Prototype for builtin assertion failure
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

// Called on violation
void reach_error() {
    __assert_fail("0", "elevator.c", 10, "reach_error");
}

// Abort if not cond
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    // Elevator state variables
    int currentFloor = 0; // 0..5
    int doorOpen = 0;     // 0 = closed, 1 = open
    int moving = 0;       // 0 = stopped, 1 = moving
    int direction = 0;    // -1 = down, +1 = up, 0 = stopped

    // Statistics
    int visits[6] = {0, 0, 0, 0, 0, 0};
    int totalVisits = 0;

    // Command definitions:
    // 1 = move up
    // 2 = move down
    // 3 = open door
    // 4 = close door
    // 5 = maintenance (exit)
    while (1) {
        int cmd = __VERIFIER_nondet_int();
        // Only commands 1..5 are valid, else exit
        if (cmd < 1 || cmd > 5) {
            break;
        }

        switch (cmd) {
        case 1: // Move up
            // Cannot move if door open
            if (currentFloor < 5) {
                moving = 1;
                direction = +1;
                currentFloor = currentFloor + 1;
                // Arrived
                moving = 0;
                direction = 0;
            }
            break;

        case 2: // Move down
            if (currentFloor > 0) {
                moving = 1;
                direction = -1;
                currentFloor = currentFloor - 1;
                moving = 0;
                direction = 0;
            }
            break;

        case 3: // Open door
            // Cannot open door while moving
            if (!doorOpen) {
                doorOpen = 1;
                visits[currentFloor]++;
                totalVisits++;
            }
            break;

        case 4: // Close door
            if (doorOpen) {
                doorOpen = 0;
            }
            break;

        case 5: // Maintenance: exit loop
            goto EXIT_LOOP;

        default:
            // Should not reach here
            break;
        }

        // Safety invariant: doorOpen and moving cannot both be true
        __VERIFIER_assert(!(doorOpen && moving));
    }

EXIT_LOOP:
    // Post-condition: the sum of visits[] equals totalVisits
    {
        int sum = 0;
        for (int i = 0; i < 6; i++) {
            sum = sum + visits[i];
        }
    }

    return 0;
}