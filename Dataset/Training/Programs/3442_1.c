// count_categories.c
// A C program that classifies array elements into negative, positive, and zero,
// then asserts that the total count matches the array size.

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() {
    __assert_fail("0", "count_categories.c", 5, "reach_error");
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
void *malloc(unsigned int size);

int main() {
    int N = __VERIFIER_nondet_int();
    if (N <= 0) {
        // No work for non‐positive sizes
        return 0;
    }
    // bound N to a reasonable size for verification
    assume_abort_if_not(N <= 10000);

    // allocate array
    int *arr = (int *)malloc(sizeof(int) * N);
    if (!arr) {
        // out of memory
        return 0;
    }

    // initialize entries nondeterministically but within a fixed range
    int i;
    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= -100 && arr[i] <= 100);
    }

    // count negatives, positives, and zeros
    int neg = 0, pos = 0, zero = 0;
    for (i = 0; i < N; i++) {
        if (arr[i] < 0) {
            neg++;
        } else if (arr[i] > 0) {
            pos++;
        } else {
            zero++;
        }
    }

    // final check: the sum of all categories must equal N
    __VERIFIER_assert(neg + pos + zero == N);

    return 0;
}