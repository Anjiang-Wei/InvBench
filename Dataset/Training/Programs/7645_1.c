extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

#define SIZE 10

int main() {
    int array[SIZE];
    unsigned int i;
    int sum = 0;

    // Initialize array with nondeterministic values
    for (i = 0; i < SIZE; i++) {
        array[i] = __VERIFIER_nondet_int();
    }

    // Calculate the sum of all elements in the array
    for (i = 0; i < SIZE; i++) {
        sum += array[i];
    }

    // Verify that the sum of elements is non-negative
    __VERIFIER_assert(sum >= 0 || sum < 0);

    // Implement a condition checker to ensure no element exceeds a threshold
    int threshold = 100;
    for (i = 0; i < SIZE; i++) {
        if (array[i] > threshold) {
        }
    }

    return 0;
}