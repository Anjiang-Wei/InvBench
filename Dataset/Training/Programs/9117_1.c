#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "new_example.c", 6, "reach_error"); }
extern int __VERIFIER_nondet_int(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
    }
    return;
}

int main(void) {
    int n;
    n = __VERIFIER_nondet_int();
    assume_abort_if_not(n >= 0 && n <= 512); // assuming n within a reasonable range

    int total = 0, count = 0;
    while (total <= 1024) {
        if (count >= n) {
            break;
        }
        count += 1;

        // Add squares of the count to the total
        total += count * count;
    }

    // Ensure the final count does not exceed n
    __VERIFIER_assert(count <= n);

    // Display the computed values
    printf("Final count: %d, Total: %d\n", count, total);

    return 0;
}