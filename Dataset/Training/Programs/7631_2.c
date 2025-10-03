#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() {
    printf("Error reached!\n");
    abort();
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

typedef struct {
    int position;
    int velocity;
} Particle;

void update_particle(Particle *p, int acceleration, int max_velocity) {
    p->velocity += acceleration;
    if (p->velocity > max_velocity) {
        p->velocity = max_velocity;
    }
    p->position += p->velocity;
}

int main() {
    Particle p1, p2;
    int initial_pos1, initial_pos2, accel1, accel2, n, max_vel;

    initial_pos1 = __VERIFIER_nondet_int();
    initial_pos2 = __VERIFIER_nondet_int();
    accel1 = __VERIFIER_nondet_int();
    accel2 = __VERIFIER_nondet_int();
    n = __VERIFIER_nondet_int();
    max_vel = __VERIFIER_nondet_int();

    assume_abort_if_not(initial_pos1 >= 0 && initial_pos2 >= 0 && accel1 >= 0 && accel2 >= 0 && n >= 0 && n <= 100 && max_vel >= 0 && max_vel <= 100);

    p1.position = initial_pos1;
    p1.velocity = 0;
    p2.position = initial_pos2;
    p2.velocity = 0;

    for (int i = 0; i < n; i++) {
        update_particle(&p1, accel1, max_vel);
        update_particle(&p2, accel2, max_vel);

        // Ensures that the positions are always initialized
    }

    // Check that the positions are non-negative
    __VERIFIER_assert(p1.position >= 0 && p2.position >= 0);

    return 0;
}