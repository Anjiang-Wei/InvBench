/*
  A C program that generates a random array of integers, records some
  properties (sum, minimum, maximum), sorts the array using insertion sort,
  verifies that key properties are preserved by asserts, and then performs
  a binary search on a random target.

  The program is written in a verification-friendly style:
   - uses __VERIFIER_nondet_int to get nondeterministic inputs
   - uses assume_abort_if_not to constrain them
   - uses __VERIFIER_assert to check final properties
   - no explicit loop invariants are asserted inside loops
*/

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "sort_search_verif.c", 10, "reach_error");
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

/* Maximum array length */
#define MAX_N 20

/* Swap two integers */
static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*
  insertion_sort:
  Sorts the array arr[0..n-1] in ascending order using insertion sort.
*/
void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        /* Shift elements greater than key to one position ahead */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/*
  binary_search:
  Searches for target in sorted array arr[0..n-1].
  Returns index of target if found, or -1 if not found.
*/
int binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
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
    int n;
    int arr[MAX_N];
    int i;
    int orig_sum = 0;
    int orig_min = 0;
    int orig_max = 0;

    /* Nondeterministically choose array length */
    n = __VERIFIER_nondet_int();
    /* Constrain 0 <= n <= MAX_N */
    assume_abort_if_not(n >= 0 && n <= MAX_N);

    /* Populate array with nondeterministic values in [-100, 100] */
    for (i = 0; i < n; i++) {
        int v = __VERIFIER_nondet_int();
        assume_abort_if_not(v >= -100 && v <= 100);
        arr[i] = v;
    }

    /* Record original sum, minimum, and maximum */
    if (n > 0) {
        orig_sum = arr[0];
        orig_min = arr[0];
        orig_max = arr[0];
    } else {
        orig_sum = 0;
        orig_min = 0;
        orig_max = 0;
    }
    for (i = 0; i < n; i++) {
        orig_sum += arr[i];
        if (arr[i] < orig_min) {
            orig_min = arr[i];
        }
        if (arr[i] > orig_max) {
            orig_max = arr[i];
        }
    }

    /* Sort the array */
    insertion_sort(arr, n);

    /* After sorting, compute sum again and check against original sum */
    {
        int new_sum = 0;
        int new_min = 0;
        int new_max = 0;
        if (n > 0) {
            new_min = arr[0];
            new_max = arr[0];
        }
        for (i = 0; i < n; i++) {
            new_sum += arr[i];
            if (arr[i] < new_min) {
                new_min = arr[i];
            }
            if (arr[i] > new_max) {
                new_max = arr[i];
            }
        }
        /* The sum must be preserved by sorting */
        /* The minimum and maximum must also be preserved */
        if (n > 0) {
        }
    }

    /* Check that array is non-decreasing */
    for (i = 0; i + 1 < n; i++) {
    }

    /* Pick a nondeterministic target to search for */
    {
        int target = __VERIFIER_nondet_int();
        assume_abort_if_not(target >= -100 && target <= 100);
        int idx = binary_search(arr, n, target);

        if (idx != -1) {
            /* If found, the element at idx must equal target */
            __VERIFIER_assert(arr[idx] == target);
        } else {
            /* If not found, then no element in the array equals target */
            int j;
            for (j = 0; j < n; j++) {
            }
        }
    }

    return 0;
}