#include <assert.h>
#include <stdio.h>

void reach_error(void) {
    assert(0);
}

extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

// A struct containing two integers
struct point {
    int x, y;
};

int calculate_distance(struct point *p1, struct point *p2) {
    int dx = p2->x - p1->x;
    int dy = p2->y - p1->y;
    return dx * dx + dy * dy; // Return square of the distance
}

// This program attempts to find the point pair with the maximum distance
int main() {
    struct point points[5];

    // Initialize points with non-deterministic values
    for (int i = 0; i < 5; i++) {
        points[i].x = __VERIFIER_nondet_int();
        points[i].y = __VERIFIER_nondet_int();
    }

    int max_distance = 0;
    struct point *max_p1 = &points[0];
    struct point *max_p2 = &points[1];

    // Iterate over all pairs of points
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            int dist = calculate_distance(&points[i], &points[j]);
            if (dist > max_distance) {
                max_distance = dist;
                max_p1 = &points[i];
                max_p2 = &points[j];
            }
        }
    }

    // A condition to be checked for verification
    if (max_distance > 0) {
        __VERIFIER_assert(max_p1 != NULL && max_p2 != NULL);
    }

    printf("Max distance between points (%d, %d) and (%d, %d) is: %d\n",
           max_p1->x, max_p1->y, max_p2->x, max_p2->y, max_distance);

    return 0;
}