#include <stdio.h>

int main(int argc, char **argv)
{
    int chars[5];

    for (int j = 0; j < 5; j++)
    {
        printf("input: \n");
        int ch;
        do
        {
            ch = getchar();
        } while (ch == '\n');
        chars[j] = ch;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("You typed the character: %c\n", chars[i]);
    }
}
