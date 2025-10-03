#include <stdio.h>
#include <stdlib.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() {
    __assert_fail("0", "example.c", 6, "reach_error");
}

void __VERIFIER_assert(int cond) {
    if (!cond) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

int complex_computation(int x, int y) {
    int result = 0;
    for (int i = 0; i < x; i++) {
        result += y * i;
        if (result > 1000) {
            break;
        }
    }
    return result;
}

int recursive_function(int a, int b) {
    if (a < 0 || b < 0) {
        return 0;
    }
    if (a == 0 || b == 0) {
        return 1;
    }
    return a * recursive_function(a - 1, b) + b * recursive_function(a, b - 1);
}

int main() {
    int x = 5;
    int y = 3;
    int z = complex_computation(x, y);

    __VERIFIER_assert(z < 1000);

    int a = 4;
    int b = 2;
    int result = recursive_function(a, b);

    printf("Complex computation result: %d\n", z);
    printf("Recursive function result: %d\n", result);

    return 0;
}