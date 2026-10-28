// Today is Tuesday. What day was it 0, 1, 2, ... 7 days ago?
//
// Should print:
//   0 days ago: Tue
//   1 days ago: Mon
//   2 days ago: Sun
//   3 days ago: Sat
//   4 days ago: Fri
//   5 days ago: Thu
//   6 days ago: Wed
//   7 days ago: Tue
#include <stdio.h>

// Days are numbered 0 (Sun) to 6 (Sat).
// Returns the day number it was k days before day. k is from 0 to 7.
int days_ago(int day, int k) {
    return (day - k) % 7;
}

// Do not modify this function.
const char *day_name(int day) {
    const char *names[7] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
    if (day < 0 || day > 6) {
        return "???";
    }
    return names[day];
}

// Do not modify this function.
int main(void) {
    int today = 2; // Tue
    for (int k = 0; k <= 7; k++) {
        int d = days_ago(today, k);
        printf("%d days ago: %s\n", k, day_name(d));
    }
    return 0;
}
