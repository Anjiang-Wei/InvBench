#include <stdlib.h>

void reach_error() { abort(); }
extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);
void __VERIFIER_assert(int cond) {
    if (!cond) {
        reach_error();
    }
}

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

/*
This function checks if a number is a Harshad (or Niven) number.
A Harshad number is an integer that is divisible by the sum of its digits.
*/
_Bool is_harshad_number(int n) {
    if (n == 0) {
        return 0;
    }
    int sum = sum_of_digits(n);
    return n % sum == 0;
}

int main() {
    int x, number, count;

    x = __VERIFIER_nondet_int();
    number = 0;
    count = 0;

    assume_abort_if_not(x >= 1 && x <= 10000);

    // Attempt to find at least one Harshad number between 1 and x
    while (number < x) {
        number++;
        if (is_harshad_number(number)) {
            count++;
        }
    }

    // We assert that at least one Harshad number is found before or equal to x (e.g., 1 is always Harshad)
    __VERIFIER_assert(count >= 1);

    return 0;
}