// Binary search verification example
// Given a sorted array a[0..3] and a target value,
// the program performs binary search and then asserts
// that the result is correct.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "binary_search.c", 10, "reach_error");
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
    int a[4];
    int target;
    int l, r, mid, found;

    // Nondeterministic initialization
    for (int i = 0; i < 4; i++) {
        a[i] = __VERIFIER_nondet_int();
        // constrain the values to a small range
        assume_abort_if_not(a[i] >= 0 && a[i] <= 100);
    }
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 0 && target <= 100);

    // Assume the array is sorted non-decreasingly
    assume_abort_if_not(a[0] <= a[1]);
    assume_abort_if_not(a[1] <= a[2]);
    assume_abort_if_not(a[2] <= a[3]);

    // Binary search for target in a[0..3]
    l = 0;
    r = 3;
    found = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == target) {
            found = mid;
            break;
        } else if (a[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    // Final correctness assertion:
    // If found != -1, then a[found] == target and index in range.
    // Otherwise, target does not appear in the array.
    __VERIFIER_assert(
        (found >= 0 && found < 4 && a[found] == target) ||
        (found == -1 && a[0] != target && a[1] != target && a[2] != target && a[3] != target));

    return 0;
}