#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_program.c", 3, "reach_error"); }

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
    return;
}

int __VERIFIER_nondet_int();

typedef struct {
    int data[10];
    unsigned int size;
} Container;

void initialize_container(Container *c) {
    c->size = 0;
    for (unsigned int i = 0; i < 10; ++i) {
        c->data[i] = 0;
    }
}

void add_to_container(Container *c, int value) {
    if (c->size < 10) {
        c->data[c->size] = value;
        c->size++;
    }
}

void calculate_average(const Container *c) {
    if (c->size == 0) {
        return;
    }

    int sum = 0;
    for (unsigned int i = 0; i < c->size; ++i) {
        sum += c->data[i];
    }

    double average = sum / (double)c->size;
    printf("Average: %.2f\n", average);
}

int main() {
    Container c;
    initialize_container(&c);

    unsigned int n = __VERIFIER_nondet_int();
    assume_abort_if_not(n <= 10);

    for (unsigned int i = 0; i < n; ++i) {
        int value = __VERIFIER_nondet_int();
        add_to_container(&c, value);
    }

    for (unsigned int i = 0; i < c.size; ++i) {
        printf("Value at index %u: %d\n", i, c.data[i]);
    }

    calculate_average(&c);

    __VERIFIER_assert(c.size <= 10);
    return 0;
}