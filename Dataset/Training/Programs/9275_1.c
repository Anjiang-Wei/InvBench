extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *)
    __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));
void reach_error() { __assert_fail("0", "custom_verifiable_program.c", 3, "reach_error"); }

extern int __VERIFIER_nondet_int(void);
extern _Bool __VERIFIER_nondet_bool(void);

void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}

void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        abort();
    }
    return;
}

struct complex_data {
    int x, y;
};

struct complex_data data_array[100];

int main() {
    int i, n = __VERIFIER_nondet_int();
    int threshold = __VERIFIER_nondet_int();
    struct complex_data current_data;
    _Bool flag = __VERIFIER_nondet_bool();

    assume_abort_if_not(n >= 0 && n <= 100); // Assume n is valid size

    for (i = 0; i < n; i++) {
        data_array[i].x = __VERIFIER_nondet_int();
        data_array[i].y = __VERIFIER_nondet_int();

        // Update threshold with a constraint
        if (data_array[i].x < threshold) {
            threshold = data_array[i].x;
        }
    }

    while (flag) {
        // Fetch a current data item
        current_data = data_array[__VERIFIER_nondet_int() % n];

        // Check and update flag based on a condition
        if (current_data.x + current_data.y > threshold * 2) {
            flag = 0;
        } else {
            current_data.x = current_data.x + 1;
        }
    }

    // Final verification
    for (i = 0; i < n; i++) {
        __VERIFIER_assert(data_array[i].x <= threshold || flag == 0);
    }

    return 0;
}