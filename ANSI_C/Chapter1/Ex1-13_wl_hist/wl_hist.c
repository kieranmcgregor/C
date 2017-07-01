#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define IN 1
#define OUT 0
#define LONGEST 50
#define NONZEROLEN 1

// display horizontal histogram of word length frequency
int main()
{
    int c, i, j, length, state;

    state = OUT;
    length = 0;

    int hist[LONGEST];
    for (i = 0; i < LONGEST; i++)
    {
        hist[i] = 0;
        // printf("%d", hist);
    }

    printf("Please enter a string:\n");

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            hist[length - NONZEROLEN]++;
            length = 0;
        }
        else if (state == OUT)
        {
            state = IN;
            length++;
        }
        else
        {
            length++;
        }
    }

    for (i = 0; i < LONGEST; i++)
    {
        if (hist[i] > 0)
        {
            printf("%2d - %2d |", (i + NONZEROLEN), hist[i]);
            for (j = NONZEROLEN; j <= hist[i]; j++)
            {
                printf("=");
            }
            printf("\n");
        }
    }
    return 0;
}
