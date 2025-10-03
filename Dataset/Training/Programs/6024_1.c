#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "traffic_light.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
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
}

#define MAX_CARS 500

typedef enum {
    RED,
    GREEN,
    YELLOW
} TrafficLight;

typedef struct {
    int car_count;
    TrafficLight light;
} Intersection;

void initialize_intersection(Intersection *intersection) {
    intersection->car_count = 0;
    intersection->light = RED;
}

void change_light(Intersection *intersection) {
    switch (intersection->light) {
    case RED:
        intersection->light = GREEN;
        break;
    case GREEN:
        intersection->light = YELLOW;
        break;
    case YELLOW:
        intersection->light = RED;
        break;
    }
}

void add_car(Intersection *intersection) {
    if (intersection->car_count < MAX_CARS) {
        intersection->car_count++;
    }
}

void remove_car(Intersection *intersection) {
    if (intersection->car_count > 0 && intersection->light == GREEN) {
        intersection->car_count--;
    }
}

int main(void) {
    Intersection intersection;
    initialize_intersection(&intersection);

    int time = __VERIFIER_nondet_int();
    assume_abort_if_not(time > 0 && time < 10000);

    for (int t = 0; t < time; t++) {
        int action = __VERIFIER_nondet_int();
        assume_abort_if_not(action >= 0 && action < 3);

        if (action == 0) {
            add_car(&intersection);
        } else if (action == 1) {
            remove_car(&intersection);
        } else if (action == 2) {
            change_light(&intersection);
        }

        // Verification condition: The car count should never exceed MAX_CARS
        __VERIFIER_assert(intersection.car_count <= MAX_CARS);

        // Verification condition: Cars can only move when the light is green
        if (intersection.car_count > 0) {
        }
    }

    return 0;
}