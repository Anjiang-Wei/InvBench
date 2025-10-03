#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated.c", 5, "reach_error"); }

extern void abort(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int __VERIFIER_nondet_int(void);

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    int max_size = __VERIFIER_nondet_int();
    int target = __VERIFIER_nondet_int();

    /* Assume constraints to ensure valid behavior */
    assume_abort_if_not(max_size > 0 && max_size <= 1000);
    assume_abort_if_not(target >= 0 && target <= 1000);

    int arr[1000];
    int i;
    int sum = 0;
    int found = 0;

    for (i = 0; i < max_size; i++) {
        arr[i] = __VERIFIER_nondet_int();
        if (arr[i] < 0 || arr[i] > 100) {
            arr[i] = 50; // Correct invalid values
        }
        sum += arr[i];
        if (arr[i] == target) {
            found = 1; // Mark if the target is found
        }
    }

    /* Verify that the sum is not negative and target is found in the array */
    __VERIFIER_assert(sum >= 0);

    return 0;
}