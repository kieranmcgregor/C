#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
// find and replace white space with escape character
int main()
{
    int c;

    printf("Please type a string:\n");

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\\\");

        }
        else
        {
            putchar(c);
        }
    }

    return 0;
}
