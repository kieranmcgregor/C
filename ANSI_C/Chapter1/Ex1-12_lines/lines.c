#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, state;

    state = OUT;

    while ((c = getchar()) != EOF)
    {
        if (c == '@')
        {
            break;
        }
        else if (c == ' ' || c == '\t' || c == '\n')
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
