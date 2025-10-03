#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
void reach_error() { abort(); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
    }
}

// A structure representing a simple Point in 2D space
typedef struct {
    int x;
    int y;
} Point;

// Function to compute Euclidean distance squared between two points
int distance_squared(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// Initializes an array of points on a line y = x
void initialize_points(Point *points, int n) {
    for (int i = 0; i < n; i++) {
        points[i].x = i;
        points[i].y = i;
    }
}

int main() {
    const int n = 10; // number of points
    Point points[n];
    initialize_points(points, n);

    // Calculate the sum of distances from the origin for each point
    int total_distance = 0;
    for (int i = 0; i < n; i++) {
        total_distance += distance_squared((Point){0, 0}, points[i]);
        __VERIFIER_assert(total_distance >= 0); // Ensure total distance is non-negative
    }

    // Partition the points into two groups by a line y = x + c
    int c = __VERIFIER_nondet_int();
    int group1_count = 0;
    int group2_count = 0;

    for (int i = 0; i < n; i++) {
        if (points[i].y > points[i].x + c) {
            group1_count++;
        } else {
            group2_count++;
        }
    }
}