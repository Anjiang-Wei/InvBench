/*
  Simple bounded buffer simulation with basic constraints
  The program contains a loop and checks some constraints within
  array manipulation using non-deterministic inputs.
*/

#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "bounded_buffer.c", 7, "reach_error"); }
extern void abort(void);
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
extern int __VERIFIER_nondet_int(void);

int main() {
    int size = __VERIFIER_nondet_int();
    assume_abort_if_not(size >= 5 && size <= 10);

    int buffer[size];
    int i, count = 0;

    // Initialize buffer with zeros
    for (i = 0; i < size; i++) {
        buffer[i] = 0;
    }

    // Fill the buffer with some non-deterministic values
    for (i = 0; i < size; i++) {
        buffer[i] = __VERIFIER_nondet_int();
        assume_abort_if_not(buffer[i] >= 0 && buffer[i] <= 10);
    }

    // Compute the sum of the values in the buffer
    int sum = 0;
    for (i = 0; i < size; i++) {
        sum += buffer[i];
    }

    // Validate the sum against a condition
    assume_abort_if_not(sum >= 10);

    // Process buffer and count valid entries
    for (i = 0; i < size; i++) {
        if (buffer[i] % 2 == 0) {
            count++;
        }
    }

    // Assert a property about the count of valid entries
    __VERIFIER_assert(count <= size);

    return 0;
}