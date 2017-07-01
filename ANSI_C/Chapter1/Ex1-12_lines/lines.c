#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define IN 1
#define OUT 0

// display user defined input, one word per line
int main()
{
    int c, state;

    state = OUT;

    printf("Please enter a string:\n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            printf("\n");
        }
        else if (state == OUT)
        {
            state = IN;
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
