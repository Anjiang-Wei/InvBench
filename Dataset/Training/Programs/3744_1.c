#include <assert.h>
#include <stdio.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "generated_program.c", 3, "reach_error"); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

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
    int x = __VERIFIER_nondet_int();
    int y = __VERIFIER_nondet_int();
    int z = __VERIFIER_nondet_int();

    // Constraints
    assume_abort_if_not(x >= 0);
    assume_abort_if_not(y >= 1 && y <= 10);
    assume_abort_if_not(z == 0); // z is initialized to 0

    int counter = 0;

    while (counter < y) {
        if (x % 3 == 0) {
            z += 2;
        } else {
            z -= 1;
        }

        if (z < 0) {
            z += 5; // keep z non-negative
        }

        x++;
        counter++;
    }

    // Postcondition that should hold: z is bounded
    __VERIFIER_assert(z >= 0 && z < 15);

    printf("Final values: x = %d, y = %d, z = %d\n", x, y, z);
    return 0;
}