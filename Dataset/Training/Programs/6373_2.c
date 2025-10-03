// This program is an illustrative example that simulates an elevator control system
// It includes state management and safety constraints to ensure correct operation.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_FLOORS 10

// Function prototypes
void reach_error();
void __VERIFIER_assert(int cond);
extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond);

enum Direction { UP,
                 DOWN,
                 IDLE };

typedef struct {
    int current_floor;
    enum Direction direction;
    _Bool doors_open;
} Elevator;

void reach_error() {
    assert(0);
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

Elevator init_elevator() {
    Elevator e;
    e.current_floor = 0;
    e.direction = IDLE;
    e.doors_open = 0;
    return e;
}

void move_elevator(Elevator *e, int target_floor) {
    assume_abort_if_not(target_floor >= 0 && target_floor < MAX_FLOORS);

    if (e->current_floor < target_floor) {
        e->direction = UP;
    } else if (e->current_floor > target_floor) {
        e->direction = DOWN;
    } else {
        e->direction = IDLE;
    }

    while (e->current_floor != target_floor) {
        if (e->direction == UP) {
            e->current_floor++;
        } else if (e->direction == DOWN) {
            e->current_floor--;
        }
    }

    e->direction = IDLE;
    e->doors_open = 1;
}

void close_doors(Elevator *e) {
    e->doors_open = 0;
}

int main() {
    Elevator elevator = init_elevator();
    int request_floor;

    for (int i = 0; i < 100; i++) {
        request_floor = __VERIFIER_nondet_int();
        assume_abort_if_not(request_floor >= 0 && request_floor < MAX_FLOORS);

        if (!elevator.doors_open) {
            move_elevator(&elevator, request_floor);
        }

        __VERIFIER_assert(elevator.current_floor == request_floor);
        close_doors(&elevator);
    }

    return 0;
}