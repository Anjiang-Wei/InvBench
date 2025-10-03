#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "newprogram.c", 5, "reach_error"); }
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
    int length, width, perimeter, area;
    length = __VERIFIER_nondet_int();
    width = __VERIFIER_nondet_int();

    assume_abort_if_not(length > 0);
    assume_abort_if_not(width > 0);

    perimeter = 2 * (length + width);
    area = length * width;

    // Checking relationship between area and perimeter
    int i = 0;
    int safe_limit = 100000; // Prevent infinite loops for safety
    while (i < 5 && i < safe_limit) {
        if (perimeter > area) {
            area += length; // Increase the area
        } else if (area > perimeter) {
            perimeter += width; // Increase the perimeter
        } else {
            break; // They are balanced or equal
        }
        i++;
    }

    __VERIFIER_assert(i <= 5);

    return 0;
}