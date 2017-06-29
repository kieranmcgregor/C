#include <stdio.h>

#define IN 1
#define OUT 0
#define LONGEST 51
#define NONZEROLEN 1

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

    while ((c = getchar()) != EOF)
    {
        if (c == '@')
        {
            break;
        }
        else if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            hist[length]++;
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

    for (i = NONZEROLEN; i < LONGEST; i++)
    {
        if (hist[i] > 0)
        {
            printf("%d - %d |", i, hist[i]);
            for (j = NONZEROLEN; j <= hist[i]; j++)
            {
                printf("=");
            }
            printf("\n");
        }
    }
    return 0;
}
