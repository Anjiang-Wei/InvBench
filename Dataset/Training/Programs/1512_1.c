// Bubble sort of 3 integers with post-condition check

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "sort3.c", 4, "reach_error"); }

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
    /* Nondeterministic inputs, constrained to avoid overflow */
    int a0 = __VERIFIER_nondet_int();
    int a1 = __VERIFIER_nondet_int();
    int a2 = __VERIFIER_nondet_int();
    assume_abort_if_not(a0 >= 0 && a0 <= 100);
    assume_abort_if_not(a1 >= 0 && a1 <= 100);
    assume_abort_if_not(a2 >= 0 && a2 <= 100);

    int arr[3] = {a0, a1, a2};
    int i, j, tmp;

    /* Standard bubble sort */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    /* Post-condition: array must be sorted */
    __VERIFIER_assert(arr[0] <= arr[1]);

    return 0;
}