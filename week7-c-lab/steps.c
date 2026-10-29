// A week of step counts, full of "magic numbers". Give them names.
//
// Goal: the output stays exactly the same (run it now and save it, see the README),
// but these numbers no longer appear as bare numbers inside main():
//   - 7, the number of days in a week   -> name it with #define
//   - 8000, the daily step goal         -> name it with const
//   - 0 to 6, the days Mon through Sun  -> name them with an enum, so that
//                                          steps[5] reads as steps[SAT]
//
// Hints:
//   Lecture: there are three ways to give a value a name. Which one is handled before
//   the compiler even runs, and which ones does the compiler itself know about?
//   An enum's first name is 0 unless you say otherwise. What's the second one?
//   Try const for the array size too. What does clang say about int steps[...] = { ... } ?
//   Where do the names go: inside main(), or above it?
#include <stdio.h>

// Do not modify this function.
void print_bar(int steps) {
    for (int i = 0; i < steps / 1000; i++) {
        printf("#");
    }
    printf(" %d\n", steps);
}

int main(void) {
    int steps[7] = { 6200, 9100, 8000, 4300, 10250, 12800, 3900 };
    const char *day_name[7] = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };

    int total = 0;
    int goal_days = 0;
    for (int day = 0; day < 7; day++) {
        printf("%s ", day_name[day]);
        print_bar(steps[day]);
        total += steps[day];
        if (steps[day] >= 8000) {
            goal_days++;
        }
    }

    printf("Average: %d steps a day\n", total / 7);
    printf("Met the %d goal on %d of %d days\n", 8000, goal_days, 7);
    printf("Weekend total: %d\n", steps[5] + steps[6]);
    if (steps[0] < steps[4]) {
        printf("Friday beat Monday\n");
    }
    return 0;
}
