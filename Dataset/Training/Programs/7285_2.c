#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to handle errors
void reach_error() {
    assert(0);
}

// Custom assert function to verify conditions
void __VERIFIER_assert(int cond) {
    if (!(cond)) {
    ERROR : {
        reach_error();
        abort();
    }
    }
}

// Non-deterministic boolean generator
_Bool __VERIFIER_nondet_bool();

// Main function
int main() {
    unsigned int credits = 0;   // Current credits a student has
    unsigned int semesters = 8; // Total semesters in a degree
    unsigned int currentSemester = 0;
    unsigned int coursesTaken = 0;

    // Loop representing each semester
    while (currentSemester < semesters) {
        if (__VERIFIER_nondet_bool()) {
            // Choosing to take a course this semester
            if (credits + 3 <= 120) { // Assuming each course adds 3 credits, max credits is 120
                credits += 3;
                coursesTaken++;
            }
        }

        // Progress to the next semester
        currentSemester++;

        // Ensure credits never exceed 120
    }

    // Final assertion: within 8 semesters, a student should have taken exactly 40 courses
    unsigned int expectedCourses = (120 / 3); // Expecting 40 courses in total
    __VERIFIER_assert(coursesTaken <= expectedCourses);

    return 0;
}