#include <stdio.h>
#include <string.h>

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__((__nothrow__, __leaf__)) __attribute__((__noreturn__));

void reach_error() { __assert_fail("0", "password_check.c", __LINE__, "reach_error"); }
extern void assume_abort_if_not(int cond) {
    if (!cond) {
        abort();
    }
}
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : { reach_error(); }
        abort();
    }
}
extern int __VERIFIER_nondet_int(void);

// Simple hash function for demonstration
unsigned int hash_password(const char *password) {
    unsigned int hash = 0;
    while (*password) {
        hash = (hash << 5) + *password;
        password++;
    }
    return hash;
}

int main() {
    char correct_password[] = "password123";
    unsigned int correct_hash = hash_password(correct_password);

    char input_password[20];
    unsigned int input_hash;
    int valid_attempts = 0;
    int max_attempts = 3; // Maximum allowed attempts

    while (valid_attempts < max_attempts) {
        printf("Enter your password: ");
        // Simulate user input for verification analysis
        int len = __VERIFIER_nondet_int();
        assume_abort_if_not(len > 0 && len < 20);

        for (int i = 0; i < len; i++) {
            input_password[i] = (char)(__VERIFIER_nondet_int() % 256);
        }
        input_password[len] = '\0';

        input_hash = hash_password(input_password);

        if (input_hash == correct_hash) {
            printf("Password correct.\n");
            return 0;
        } else {
            printf("Password incorrect.\n");
            valid_attempts++;
        }
    }

    printf("Access denied.\n");
    __VERIFIER_assert(valid_attempts <= max_attempts);

    return 1;
}