#include <stdio.h>

// ' ' = 32 to '~' = 126
#define SPACE 32
#define TILDE 126
#define CHARANG (TILDE - SPACE)

int main()
{
    int c, i, j, quit;

    int hist[CHARANG];
    for (i = 0; i < CHARANG; i++)
    {
        hist[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (c == '@')
        {
            break;
        }
        else
        {
            hist[c - SPACE]++;
        }
    }

    for (i = 0; i < CHARANG; i++)
    {
        if (hist[i] > 0)
        {
            printf("'%1c' - %3d |", (i + SPACE), hist[i]);
            for (j = 0; j < hist[i]; j ++)
            {
                printf("=");
            }
            printf("\n");
        }
    }

    return 0;
}
