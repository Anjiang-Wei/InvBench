#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__))
    __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
    return;
}

int main() {
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int count = 0;
    unsigned int n = 10; // Set the number of iterations

    while (count < n) {
        a += b * 2; // Increment 'a' with double 'b'
        b += 3;     // Increment 'b' by 3
        count++;
    }

    // Assert that 'a' is not equal to 150 at the end
    __VERIFIER_assert(a != 150);

    printf("Final value of a: %u\n", a);
    printf("Final value of b: %u\n", b);
    return 0;
}