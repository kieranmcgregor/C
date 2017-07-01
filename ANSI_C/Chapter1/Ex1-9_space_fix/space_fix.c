#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define R 1
#define NR 0

// find and replace multiple spaces (' ') with single space (' ')
int main()
{

    int c, repeat;

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
            putchar(c);
        }
    }

    return 0;
}
