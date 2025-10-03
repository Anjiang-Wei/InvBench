#include <stdio.h>

/* External function declaration */
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "gen_121123.c", 3, "reach_error"); }

/* External nondeterministic input function */
extern int __VERIFIER_nondet_int(void);

/* Assertion function */
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
    int found = 0;
    int secret_number = 42;
    int guess_counter = 100;
    int guess;

    while (guess_counter > 0) {
        guess = __VERIFIER_nondet_int();

        if (guess == secret_number) {
            found = 1;
            break;
        } else {
            if (guess > secret_number) {
                printf("Guess (%d) is too high!\n", guess);
            } else {
                printf("Guess (%d) is too low!\n", guess);
            }
            guess_counter--;
        }
    }

    if (!found) {
    } else {
        __VERIFIER_assert(guess == secret_number && found == 1);
    }

    return 0;
}