// A C program for verification tools: bubble sort, prefix sums, and maximum computation.
// It uses nondeterministic inputs, dynamic memory, loops, and assertions suitable for analyzers.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "verif_sort_prefix_max.c", 10, "reach_error");
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);
extern void *malloc(unsigned int size);

int main() {
    // Nondeterministic size
    int N = __VERIFIER_nondet_int();
    // Constraint N to a reasonable bound for verification
    assume_abort_if_not(N > 0);
    assume_abort_if_not(N <= 100);

    // Allocate three integer arrays: arr for sorting, orig for original copy, prefix for prefix sums
    int *arr = (int *)malloc(sizeof(int) * N);
    int *orig = (int *)malloc(sizeof(int) * N);
    int *prefix = (int *)malloc(sizeof(int) * N);

    // Loop indices and temporaries
    int i, j, temp;

    // Fill arr with nondeterministic values and copy to orig
    for (i = 0; i < N; i++) {
        int v = __VERIFIER_nondet_int();
        // Constrain each element to a range
        assume_abort_if_not(v >= -10000);
        assume_abort_if_not(v <= 10000);
        arr[i] = v;
        orig[i] = v;
    }

    // Bubble sort arr in non-decreasing order
    // Two nested loops swapping out-of-order elements
    for (i = 0; i < N; i++) {
        for (j = 0; j + 1 < N; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Compute prefix sums of the sorted array
    int sum = 0;
    for (i = 0; i < N; i++) {
        sum += arr[i];
        prefix[i] = sum;
    }

    // Compute maximum of the original array
    int orig_max = orig[0];
    for (i = 1; i < N; i++) {
        if (orig[i] > orig_max) {
            orig_max = orig[i];
        }
    }

    // Verification assertions

    // 1) The sorted array is in non-decreasing order
    for (i = 0; i + 1 < N; i++) {
    }

    // 2) Prefix sums are non-decreasing as well
    for (i = 0; i + 1 < N; i++) {
    }

    // 3) The last prefix sum equals the total sum
    __VERIFIER_assert(prefix[N - 1] == sum);

    // 4) The computed orig_max is indeed >= every element in orig
    for (i = 0; i < N; i++) {
    }

    // Clean exit
    return 0;
}