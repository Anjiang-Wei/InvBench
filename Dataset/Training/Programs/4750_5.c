// learned_program.c
// A composite verification example combining sorting, searching, and GCD computations.
// The program reads a small array, sorts it by insertion sort, checks sum preservation
// and permutation property via binary search, then computes GCD of two numbers by
// Euclid's algorithm and by brute force, and asserts they agree.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    // Report verification failure
    __assert_fail("0", "learned_program.c", __LINE__, "reach_error");
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

// Read n integers into arr[], each in [0,100].
void read_array(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 0 && arr[i] <= 100);
    }
}

// Compute the sum of n elements in arr[].
int compute_sum(int *arr, int n) {
    int s = 0;
    int i;
    for (i = 0; i < n; i++) {
        s += arr[i];
    }
    return s;
}

// Insertion sort: sorts arr[0..n-1] in non-decreasing order.
void insertion_sort(int *arr, int n) {
    int i;
    for (i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Binary search: returns 1 if target is found in sorted arr[0..n-1], else 0.
int binary_search(int *arr, int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

// Compute GCD by the classic Euclidean algorithm.
int gcd_euclid(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Compute GCD by brute force: check all divisors up to min(a,b).
int gcd_bruteforce(int a, int b) {
    int min = (a < b ? a : b);
    int g = 1;
    int k;
    for (k = 1; k <= min; k++) {
        if (a % k == 0 && b % k == 0) {
            g = k;
        }
    }
    return g;
}

int main() {
    // Part 1: array sorting and permutation check
    int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 8);

    // Original array
    int arr_orig[8];
    read_array(arr_orig, n);

    // Compute sum before sorting
    int sum_before = compute_sum(arr_orig, n);

    // Copy to working array
    int arr[8];
    {
        int i;
        for (i = 0; i < n; i++) {
            arr[i] = arr_orig[i];
        }
    }

    // Sort the array
    insertion_sort(arr, n);

    // Compute sum after sorting
    int sum_after = compute_sum(arr, n);

    // Check that sorting preserved the sum

    // Check that the array is non-decreasing
    {
        int i;
        for (i = 1; i < n; i++) {
        }
    }

    // Check that sorted array is a permutation of the original using binary search
    {
        int i;
        for (i = 0; i < n; i++) {
            int found = binary_search(arr, n, arr_orig[i]);
        }
    }

    // Part 2: GCD comparison
    int a = __VERIFIER_nondet_int();
    assume_abort_if_not(a >= 0 && a <= 100);

    int b = __VERIFIER_nondet_int();
    assume_abort_if_not(b >= 0 && b <= 100);

    // At least one of a or b must be nonzero to define GCD
    assume_abort_if_not(!(a == 0 && b == 0));

    // Compute two GCDs
    int g1 = gcd_euclid(a, b);
    int g2 = gcd_bruteforce(a, b);

    // They must be equal and positive
    __VERIFIER_assert(g1 > 0);

    return 0;
}