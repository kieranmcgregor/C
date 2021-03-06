#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define IN 1
#define OUT 0

/* count lines, words and characters in input */
int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;

    printf("Please enter a string:\n");

    while ((c = getchar()) != EOF)
    {
        nc++;

        if (c == '\n')
        {
            nl++;
        }

        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            nw++;
        }
    }

    printf("Lines: %d\nWords: %d\nCharacters: %d\n", nl, nw, nc);
    return 0;
}
