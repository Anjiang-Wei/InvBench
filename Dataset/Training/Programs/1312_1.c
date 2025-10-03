#include <assert.h>
#include <stdlib.h>

void reach_error(void) { assert(0); }
extern void abort(void);
extern int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

typedef struct {
    int x, y;
} Point;

int distance_squared(Point *p1, Point *p2) {
    int dx = p1->x - p2->x;
    int dy = p1->y - p2->y;
    return dx * dx + dy * dy;
}

int main() {
    int n = __VERIFIER_nondet_int();
    if (n <= 0) {
        return 0;
    }

    Point *points = (Point *)malloc(n * sizeof(Point));
    if (!points) {
        abort();
    }

    for (int i = 0; i < n; ++i) {
        points[i].x = __VERIFIER_nondet_int();
        points[i].y = __VERIFIER_nondet_int();
    }

    int distance_threshold = __VERIFIER_nondet_int();
    if (distance_threshold < 0) {
        free(points);
        return 0;
    }

    int sum_of_distances = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int dist_sq = distance_squared(&points[i], &points[j]);
            if (dist_sq <= distance_threshold) {
                sum_of_distances += dist_sq;
            }
        }
    }

    // Check if the sum of certain pairs' distance squares exceeds a certain value
    __VERIFIER_assert(sum_of_distances >= 0);

    free(points);
    return 0;
}