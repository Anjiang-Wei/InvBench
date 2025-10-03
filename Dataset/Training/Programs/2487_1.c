#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void reach_error() { abort(); }
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int global_counter = 0;
int update_counter(int value) {
    global_counter += value;
    return global_counter;
}

void complex_operation(int input) {
    if (input % 3 == 0) {
        update_counter(-3);
    } else if (input % 3 == 1) {
        update_counter(2);
    } else {
        update_counter(1);
    }
}

int main() {
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 1000); // Ensure N is within a reasonable range

    int i, input;
    for (i = 0; i < N; i++) {
        input = __VERIFIER_nondet_int();
        assume_abort_if_not(input >= -10 && input <= 10); // Limit input to a range
        complex_operation(input);
    }

    // Verify that after N operations, the counter is within expected bounds
    __VERIFIER_assert(global_counter <= N * 2 && global_counter >= -N * 3);

    return 0;
}