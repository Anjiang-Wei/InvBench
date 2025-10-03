#include <assert.h>
extern void abort(void);
void reach_error() { assert(0); }
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

extern int __VERIFIER_nondet_int(void);

void check_divisibility(int num) {
    if (num % 3 == 0 && num % 5 == 0) {
    } else if (num % 3 == 0) {
    } else if (num % 5 == 0) {
    }
}

int main() {
    int sum = 0;
    int limit, num;
    limit = __VERIFIER_nondet_int();
    if (limit <= 0) {
        return 0;
    }

    for (int i = 0; i < limit; i++) {
        num = __VERIFIER_nondet_int();

        if (num < 0) {
            continue;
        }

        check_divisibility(num);

        if (num % 3 == 0 || num % 5 == 0) {
            sum += num;
        }
    }

    __VERIFIER_assert(sum >= 0);
    return 0;
}