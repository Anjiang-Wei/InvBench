#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 4, "reach_error"); }
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

struct point {
    int x;
    int y;
};

struct point points_array[10];

void initialize_points() {
    for (int i = 0; i < 10; i++) {
        points_array[i].x = __VERIFIER_nondet_int();
        points_array[i].y = __VERIFIER_nondet_int();
    }
}

int compute_distance(struct point p) {
    return p.x * p.x + p.y * p.y;
}

int main() {
    initialize_points();
    int total_distance = 0;
    int threshold = __VERIFIER_nondet_int();

    assume_abort_if_not(threshold > 0);

    for (int i = 0; i < 10; i++) {
        int d = compute_distance(points_array[i]);
        total_distance += d;
        if (d > threshold) {
            __VERIFIER_assert(total_distance >= 0);
        }
    }

    return 0;
}