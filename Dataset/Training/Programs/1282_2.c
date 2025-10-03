// bubble_sort.c
// A simple bubble sort on an array of 3 elements,
// suitable for automated verification.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "bubble_sort.c", 8, "reach_error");
}

extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

int main() {
    int a[3];
    int i, j, tmp;

    // Non‐deterministic inputs, constrained to a small range
    a[0] = __VERIFIER_nondet_int();
    assume_abort_if_not(a[0] >= -10 && a[0] <= 10);
    a[1] = __VERIFIER_nondet_int();
    assume_abort_if_not(a[1] >= -10 && a[1] <= 10);
    a[2] = __VERIFIER_nondet_int();
    assume_abort_if_not(a[2] >= -10 && a[2] <= 10);

    // Bubble sort for 3 elements
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            if (a[j] > a[j + 1]) {
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    // After sorting, the array must be non‐decreasing
    __VERIFIER_assert(a[1] <= a[2]);

    return 0;
}