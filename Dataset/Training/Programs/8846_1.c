#include <assert.h>
#include <stdlib.h>

extern void abort(void);
extern void reach_error(void) { assert(0); }

extern int __VERIFIER_nondet_int(void);
void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
        reach_error();
        abort();
    }
}

int main() {
    // Initialize variables and allocate memory for an array
    int N = __VERIFIER_nondet_int();
    assume_abort_if_not(N > 0 && N < 100);

    int *arr = (int *)malloc(sizeof(int) * N);
    assume_abort_if_not(arr != NULL);

    int sum = 0;
    int product = 1;
    int i;

    // Fill the array with numbers and calculate sum and product
    for (i = 0; i < N; i++) {
        arr[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(arr[i] >= 1 && arr[i] <= 10);

        sum += arr[i];
        product *= arr[i];
    }

    // A loop for conditional decision based on the sum and product
    int decision_flag = -1;
    while (sum > 0 && product < 1000000) {
        if (sum > product) {
            product += sum / N; // Increment product by average
        } else {
            sum = (sum < 10) ? 0 : sum - 10; // Decrement sum
        }

        // If sum becomes a perfect square, set decision_flag
        for (i = 1; i * i <= sum; i++) {
            if (i * i == sum) {
                decision_flag = i;
                break;
            }
        }

        if (decision_flag != -1) {
            break; // Exit the loop if decision_flag is set
        }
    }

    // Check that decisions were made correctly
    if (decision_flag != -1) {
        __VERIFIER_assert(sum == decision_flag * decision_flag);
    } else {
    }

    // Clean up
    free(arr);
    return 0;
}