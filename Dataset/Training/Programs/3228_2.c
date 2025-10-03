#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
void reach_error() { __assert_fail("0", "example.c", 4, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

typedef struct {
    int x;
    int y;
} Point;

Point *create_point(int x, int y) {
    Point *point = (Point *)malloc(sizeof(Point));
    if (point == NULL) {
        abort();
    }
    point->x = x;
    point->y = y;
    return point;
}

void destroy_point(Point *point) {
    free(point);
}

int main() {
    int a = __VERIFIER_nondet_int();
    int b = __VERIFIER_nondet_int();
    int c = __VERIFIER_nondet_int();
    int d = __VERIFIER_nondet_int();

    assume_abort_if_not(a >= 0 && a <= 10);
    assume_abort_if_not(b >= 0 && b <= 10);
    assume_abort_if_not(c >= 0 && c <= 10);
    assume_abort_if_not(d >= 0 && d <= 10);

    Point *p = create_point(a, b);
    Point *q = create_point(c, d);

    int i;
    int sum_x = 0;
    int sum_y = 0;

    for (i = 0; i < 10; i++) {
        sum_x += p->x + q->x;
        sum_y += p->y + q->y;
    }

    __VERIFIER_assert(sum_y == 10 * (p->y + q->y));

    destroy_point(p);
    destroy_point(q);

    return 0;
}