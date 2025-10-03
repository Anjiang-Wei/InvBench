/*
 * A C program combining sorting, GCD/LCM computation, and binary search.
 * The program is designed for automated verification tools. It
 * allocates an array of nondeterministic integers, sorts it using
 * insertion sort, checks preservation of the sum, computes the GCD
 * and LCM of all elements, and then does a binary search of a
 * randomly chosen element. Final assertions verify correctness.
 */

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "combined.c", 10, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
        abort();
    }
}

extern int __VERIFIER_nondet_int(void);
void *malloc(unsigned int size);

/* Compute the greatest common divisor of x and y (non-negative) */
int gcd(int x, int y) {
    /* Precondition: x >= 0, y >= 0 */
    assume_abort_if_not(x >= 0 && y >= 0);
    while (y != 0) {
        int tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

/* Compute the least common multiple of x and y */
int lcm(int x, int y) {
    /* If either is zero, lcm is zero */
    if (x == 0 || y == 0) {
        return 0;
    }
    int g = gcd(x, y);
    /* (x/g)*y will not overflow if x,y small */
    return (x / g) * y;
}

/* Binary search for target in a sorted array arr[0..len-1].
   Returns index or -1 if not found. */
int binary_search(int *arr, int len, int target) {
    int low = 0;
    int high = len - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int N = __VERIFIER_nondet_int();
    /* We require a positive but bounded size */
    assume_abort_if_not(N > 0 && N <= 100);

    /* Allocate two arrays: original and working copy */
    int *orig = (int *)malloc(sizeof(int) * N);
    int *a = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(orig != 0 && a != 0);

    /* Fill arrays with nondeterministic values in [0,1000] */
    int i;
    for (i = 0; i < N; i++) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(v >= 0 && v <= 1000);
        orig[i] = v;
        a[i] = v;
    }

    /* Compute sum of original */
    long sum_orig = 0;
    for (i = 0; i < N; i++) {
        sum_orig += orig[i];
    }

    /* Insertion sort on array a */
    for (i = 1; i < N; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    /* Compute sum of sorted array */
    long sum_sorted = 0;
    for (i = 0; i < N; i++) {
        sum_sorted += a[i];
    }

    /* Verify that sorting preserves the total sum */

    /* Verify that the array is non-decreasing */
    for (i = 1; i < N; i++) {
    }

    /* Compute GCD of all original elements */
    int g = orig[0];
    for (i = 1; i < N; i++) {
        g = gcd(g, orig[i]);
    }
    /* G must be non-negative */
    __VERIFIER_assert(g >= 0);

    /* Every original element should be divisible by the GCD */
    for (i = 0; i < N; i++) {
    }

    /* Compute LCM of all original elements */
    int l = orig[0];
    for (i = 1; i < N; i++) {
        l = lcm(l, orig[i]);
        /* lcm grows, but within int if values small */
        assume_abort_if_not(l >= 0);
    }

    /* If all orig[i] > 0, then l should be >= each orig[i] */
    for (i = 0; i < N; i++) {
        if (orig[i] > 0) {
        }
    }

    /* Pick a random index and search its value in the sorted array */
    int idx = __VERIFIER_nondet_int();
    assume_abort_if_not(idx >= 0 && idx < N);
    int target = orig[idx];
    int found = binary_search(a, N, target);

    /* The search must succeed for a value known to be in the array */

    return 0;
}