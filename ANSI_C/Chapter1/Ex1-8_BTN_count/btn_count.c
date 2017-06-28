#include <stdio.h>

/* count blanks, tabs and newline charaters in input */

int main()
{
    int c;
    long s, t, n;

    s = 0;
    t = 0;
    n = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            s++;
        } else if (c == '\t')
        {
            t++;
        } else if (c == '\n')
        {
            n++;
        } else if (c == '@')
        {
            break;
        }
    }
    printf("There are %ld spaces, %ld tabs and %ld newlines in 'c'.\n", s, t, n);

    return 0;
}
