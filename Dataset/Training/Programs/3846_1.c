/*
  Example C program demonstrating computation and constraint checks.
  This program simulates a simple traffic light system.
*/

#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "traffic_light.c", 8, "reach_error"); }
extern unsigned int __VERIFIER_nondet_uint(void);
extern void abort(void);
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

typedef enum { RED,
               GREEN,
               YELLOW } TrafficLight;

int main() {
    unsigned int cycles = __VERIFIER_nondet_uint();
    assume_abort_if_not(cycles > 0 && cycles <= 1000); // Limit the cycles for simulation safety

    TrafficLight light = RED;
    int red_time = 0, green_time = 0, yellow_time = 0;

    unsigned int cycleCounter = 0;
    while (cycleCounter++ < cycles) {
        switch (light) {
        case RED:
            red_time++;
            if (red_time >= 3) { // Example duration for RED light
                light = GREEN;
                green_time = 0; // Reset GREEN time counter
            }
            break;
        case GREEN:
            green_time++;
            if (green_time >= 4) { // Example duration for GREEN light
                light = YELLOW;
                yellow_time = 0; // Reset YELLOW time counter
            }
            break;
        case YELLOW:
            yellow_time++;
            if (yellow_time >= 2) { // Example duration for YELLOW light
                light = RED;
                red_time = 0; // Reset RED time counter
            }
            break;
        }
    }

    // Simple constraint to verify the logic of the light system
    __VERIFIER_assert((red_time >= 0 && red_time <= 3) &&
                      (green_time >= 0 && green_time <= 4) &&
                      (yellow_time >= 0 && yellow_time <= 2));

    return 0;
}