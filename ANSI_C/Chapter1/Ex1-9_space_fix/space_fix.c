#include <stdio.h>

int main()
{
    #define R 1
    #define NR 0
    #define QUIT 4

    int c, repeat, quit;

    quit = 0;

    repeat = NR;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' && repeat == NR)
        {
            putchar(c);
            repeat = R;
            continue;
        }
        else if (c == ' ' && repeat == R)
        {
            continue;
        }
        else if (c != ' ')
        {
            if (repeat == R)
            {
                repeat = NR;
            }

            if (c == '@')
            {
                quit++;
                if (quit == QUIT)
                {
                    printf("\n");
                    break;
                }
            }
            else
            {
                quit = 0;
            }
            putchar(c);
        }
    }
    return 0;
}
