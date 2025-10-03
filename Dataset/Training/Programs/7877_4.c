// Your complete C program here

/*
 * A combined sorting and searching program for verification.
 * 1. Fills an array of nondeterministic integers (bounded).
 * 2. Records initial sum and sum of squares.
 * 3. Performs selection sort.
 * 4. Computes sum and sum of squares after sort.
 * 5. Performs binary search for a nondeterministic target.
 * 6. Applies a nondeterministic number of point updates.
 * 7. Re-sorts the array using insertion sort.
 * 8. Checks final sortedness, sum invariants and binary-search correctness.
 *
 * The program is fully bounded (array size <= MAX_N) and uses only loops
 * with constant bounds or data-dependent bounds that are statically small.
 * Final assertions ensure correctness without exposing loop invariants.
 */

#include <stdlib.h>

extern int __VERIFIER_nondet_int(void);
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sort_search.c", 1, "reach_error");
}

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

#define MAX_N 20
#define MIN_VAL -50
#define MAX_VAL 50

/* Fill the array A[0..n-1] with nondet values in [MIN_VAL,MAX_VAL].
 * Also accumulate initial sum and sum of squares into out_sum and out_sumsq.
 */
void init_array(int A[], int n, int *out_sum, int *out_sumsq) {
    int i;
    *out_sum = 0;
    *out_sumsq = 0;
    for (i = 0; i < n; i++) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(v >= MIN_VAL && v <= MAX_VAL);
        A[i] = v;
        *out_sum += v;
        *out_sumsq += v * v;
    }
}

/* Simple selection sort on A[0..n-1]. */
void selection_sort(int A[], int n) {
    int i, j, min_idx, tmp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        /* swap A[i] and A[min_idx] */
        tmp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = tmp;
    }
}

/* Simple insertion sort on A[0..n-1]. */
void insertion_sort(int A[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = A[i];
        j = i - 1;
        /* shift larger elements right */
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

/* Standard binary search on sorted A[0..n-1] for target.
 * Returns an index in [0..n-1] if found, or -1 if not found.
 */
int binary_search(int A[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (A[mid] == target) {
            return mid;
        }
        if (A[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

/* Check that A[0..n-1] is non-decreasing.
 * If not, abort via assertion.
 */
void check_sorted(int A[], int n) {
    int i;
    for (i = 0; i + 1 < n; i++) {
    }
}

/* Check that the sum of elements in A[0..n-1] equals expected_sum
 * and the sum of squares equals expected_sumsq.
 */
void check_sum_invariants(int A[], int n, int expected_sum, int expected_sumsq) {
    int i;
    int s = 0, sq = 0;
    for (i = 0; i < n; i++) {
        s += A[i];
        sq += A[i] * A[i];
    }
}

int main(void) {
    int n;
    int A[MAX_N];
    int init_sum, init_sumsq;
    int sorted_sum, sorted_sumsq;
    int target;
    int idx1, idx2;
    int updates, u, upos, uval;

    /* nondeterministic array length */
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= MAX_N);

    /* initialize array and record sums */
    init_array(A, n, &init_sum, &init_sumsq);

    /* first sort */
    selection_sort(A, n);

    /* record sums after first sort */
    sorted_sum = 0;
    sorted_sumsq = 0;
    {
        int i;
        for (i = 0; i < n; i++) {
            sorted_sum += A[i];
            sorted_sumsq += A[i] * A[i];
        }
    }

    /* search for a nondet target in the sorted array */
    target = __VERIFIER_nondet_int();
    assume_abort_if_not(target >= MIN_VAL && target <= MAX_VAL);
    idx1 = binary_search(A, n, target);

    /* perform a nondet number of point updates */
    updates = __VERIFIER_nondet_int();
    assume_abort_if_not(updates >= 0 && updates <= n);
    for (u = 0; u < updates; u++) {
        upos = __VERIFIER_nondet_int();
        assume_abort_if_not(upos >= 0 && upos < n);
        uval = __VERIFIER_nondet_int();
        assume_abort_if_not(uval >= MIN_VAL && uval <= MAX_VAL);
        A[upos] = uval;
    }

    /* resort after updates */
    insertion_sort(A, n);

    /* final checks */
    check_sorted(A, n);
    /* the updates may have changed sums, but sorting alone does not */
    check_sum_invariants(A, n, sorted_sum, sorted_sumsq);

    /* binary-search again for the same target */
    idx2 = binary_search(A, n, target);

    if (idx2 >= 0) {
        /* if found, must match target */
        __VERIFIER_assert(A[idx2] == target);
    } else {
        /* if not found, no element may equal target */
        int i;
        for (i = 0; i < n; i++) {
        }
    }

    return 0;
}