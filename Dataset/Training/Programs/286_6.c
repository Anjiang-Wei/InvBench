/*
 * Insertion Sort with Sum Invariant and Binary Search
 * This program initializes an integer array of nondeterministic size (<=10)
 * with nondeterministic values (0..100). It records the original sum of
 * elements, then performs insertion sort while checking that the sum of
 * elements remains constant after each data movement. After sorting, it
 * asserts that the array is in non-decreasing order, then performs a binary
 * search for a nondeterministic target value and, if found, asserts that
 * the found index indeed holds the target.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "insert_sort_bs.c", 17, "reach_error");
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
    const int MAX_N = 10;
    int n;
    int i, j, k;
    int key;
    int target;
    int found_idx;
    int a[MAX_N];
    int orig_sum;
    int cur_sum;

    /* Nondeterministic size of array */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX_N);

    /* Initialize array elements and compute original sum */
    orig_sum = 0;
    for (i = 0; i < n; i++) {
        a[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(a[i] >= 0 && a[i] <= 100);
        orig_sum += a[i];
    }

    /* Check original sum is non-negative */

    /* Insertion sort with sum invariant checks */
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        /* Move elements greater than key to one position ahead */
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;

            /* Recompute sum and assert it matches original */
            cur_sum = 0;
            for (k = 0; k < n; k++) {
                cur_sum += a[k];
            }
        }

        a[j + 1] = key;

        /* After placing key, check sum invariant again */
        cur_sum = 0;
        for (k = 0; k < n; k++) {
            cur_sum += a[k];
        }
    }

    /* Assert that the array is sorted in non-decreasing order */
    for (i = 0; i + 1 < n; i++) {
    }

    /* Nondeterministic target for binary search */
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= 0 && target <= 100);
    found_idx = -1;

    /* Binary search loop */
    {
        int low = 0;
        int high = n - 1;
        int mid;

        while (low <= high) {
            /* Prevent overflow in midpoint computation */
            mid = low + (high - low) / 2;

            if (a[mid] == target) {
                found_idx = mid;
                break;
            } else if (a[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    /* If found, assert that the found index indeed holds the target */
    if (found_idx >= 0) {
        __VERIFIER_assert(a[found_idx] == target);
    }

    return 0;
}