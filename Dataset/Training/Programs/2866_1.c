#include <stdio.h>
#include <stdlib.h>

// Function prototypes
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "new_program.c", 10, "reach_error");
}

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

int main() {
    int max_capacity, current, rate;
    max_capacity = __VERIFIER_nondet_int();
    current = __VERIFIER_nondet_int();
    rate = __VERIFIER_nondet_int();

    assume_abort_if_not(max_capacity > 0 && rate > 0 && current >= 0 && current <= max_capacity);

    int time_steps = 0;

    while (current < max_capacity) {
        __VERIFIER_assert(current >= 0 && current <= max_capacity);

        if (time_steps > 10) {
            break;
        }

        current += rate;

        if (current > max_capacity) {
            current = max_capacity;
        }

        time_steps++;
    }

    printf("Reached maximum capacity after %d time steps.\n", time_steps);

    return 0;
}