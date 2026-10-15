/*
* tvm:  Time Value of Money
*
* Assignment 2 of CSE 13S, Fall 2026.
*/

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
* The financial calculator's variables:
*/
double N, I, PV, PMT, FV;


/*
* Purpose:      Function f(N) used by the Newton-Raphson root finder.
*
* Parameter:    Number of periods N.
*
*               See equation (7) in the assignment PDF.  For all
*               values except for N, use the global variables.  For N,
*               use the value of the parameter.
*
* Returns:      f(N)
*/
double fN(double N) {
    return 0.0; /* Delete this line, and replace it with your own C code. */
}


/*
* Purpose:      Function f(I) used by the Newton-Raphson root finder.
*
* Parameter:    Interest rate I.
*
*               See equation (12) in the assignment PDF.  For all
*               values except for I, use the global variables.  For I,
*               use the value of the parameter.
*
* Returns:      f(I)
*/
double fI(double I) {
    return 0.0; /* Delete this line, and replace it with your own C code. */
}


/*
* Purpose:      Function f'(N) used by the Newton-Raphson root finder.
*
* Parameter:    Number of periods N.
*
*               See equation (8) in the assignment PDF.  For all
*               values except for N, use the global variables.  For N,
*               use the value of the parameter.
*
* Returns:      f'(N)
*/
double fN_prime(double N) {
    return 0.0; /* Delete this line, and replace it with your own C code. */
}


/*
* Purpose:      Function f'(I) used by the Newton-Raphson root finder.
*
* Parameter:    Interest rate I.
*
*               See equation (13) in the assignment PDF.  For all
*               values except for I, use the global variables.  For I,
*               use the value of the parameter.
*
* Returns:      f'(I)
*/
double fI_prime(double I) {
    return 0.0; /* Delete this line, and replace it with your own C code. */
}


/*
* Purpose:      Find N such that fN(N) == 0 using a simple Newton-Raphson
*               root finder.
*
*               Use the pseudocode in section 6.2 of the assignment PDF
*               along with equations (6) through (10).
*
* Parameters:   line_number for error messages.
*
* Returns:      N such that fN(N) == 0.
*/
double newton_raphson_N(int line_number) {
    return 0.0; /* Delete this line, and replace it with your own C code. */
}


/*
* Purpose:      Find I such that fI(I) == 0 using a simple Newton-Raphson
*               root finder.
*
*               Use the pseudocode in section 6.3 of the assignment PDF
*               along with equations (11) through (15).
*
* Parameters:   line_number for error messages.
*
* Returns:      I such that fI(I) == 0.
*/
double newton_raphson_I(int line_number) {
    return 0.0; /* Delete this line, and replace it with your own C code. */
}


/*
* Purpose:      Check whether I is 0.0.  If it is, report an error ("I must
*               not be zero"), and exit the program with an exit code of 1.
*
*               For more information, see section 4.2 of the Assignment PDF.
*
* Parameters:   line_number for any error messages.
*
* Returns:      Nothing.
*/
void check_I(int line_number) {
}


/*
* Purpose:      Compute and print a variable's new value.
*
*               For more information, see these sections of the Assignment
*               PDF:  6.1, 6.2, and 6.3.
*
* Parameters:   name        -- of the variable to compute
*               line_number -- for any error messages
*
* Returns:      Nothing.
*/
void tvm_compute_variable(char *name, int line_number) {
}


/*
* Purpose:      Set a variable's new value.
*
* Parameters:   name and line_number for any error messages.
*               value is the variable's new value.
*
* Returns:      Nothing.
*/
void tvm_set_variable(char *name, double value, int line_number) {
}


/*
* Purpose:      Clear all of the financial variables:  N, I, PV, PMT, and FV.
*
* Parameters:   None.
*
* Returns:      Nothing.
*/
void tvm_clear(void) {
}


/*
* Purpose:      Run "Unit Tests" that test functions fN(), fI(),
*               fN_prime(), and fI_prime().
*
* Parameters:   none
*
* Returns:      nothing
*/
void run_unit_tests(void) {
    N = 5.0;
    I = 0.4;
    PV = 3.0;
    PMT = -0.2;
    FV = -1.0;

    printf("N        is %5.1f\n", N);
    printf("I        is %5.1f\n", I);
    printf("PV       is %5.1f\n", PV);
    printf("PMT      is %5.1f\n", PMT);
    printf("FV       is %5.1f\n", FV);
    printf("fN(6.0)  is %10f expect   2.433595\n", fN(6.0));
    printf("fI(0.7)  is %10f expect   2.663979\n", fI(0.7));
    printf("f'N(8.0) is %10f expect  12.414051\n", fN_prime(8.0));
    printf("f'I(0.9) is %10f expect 187.362127\n", fI_prime(0.9));
}


/*
* Purpose:      Process one of these commands, or print an error and exit.
*
*                   "set VAR NUMBER"
*                   "compute VAR"
*                   "clear"
*                   "test"
*
* Parameters:   command:        A string that represents the command.
*               line_number:    The line number of the command, for errors.
*
* Returns:      Nothing
*/
void tvm_process_command(char *command, int line_number) {
}


/*
* Purpose:      Truncate string s at the first occurance of '\n'.
*               If s has no '\n', then do nothing.
*
*               The end of a string is denoted by a 0 byte, sometimes
*               called '\0'.  So overwriting any '\n' with '\0' will
*               truncate the string just before the '\n'.
*
* Parameter:    s is a string
*
* Returns:      Nothing
*/
void truncate_at_newline(char *s) {
    int j = 0;

    while (s[j] != '\0' && s[j] != '\n') ++j;

    s[j] = '\0';
}


/*
* Purpose:      Read commands from stdin, and process them.
* Parameters:   None
* Exit code:    1 on error, else 0
*/
int main(void) {
    char command[40];

    int line_number = 0;

    tvm_clear();

    while (1) {
        char *res = fgets(command, sizeof(command), stdin);

        if (res == NULL) break;

        ++line_number;
        truncate_at_newline(command);
        tvm_process_command(command, line_number);
    }

    if (ferror(stdin)) {
        fprintf(stderr, "tvm:  Error reading input\n");
        exit(1);
    }

    return 0;
}
