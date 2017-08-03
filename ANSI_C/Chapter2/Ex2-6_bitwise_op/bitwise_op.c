#include <stdio.h>

#define MAXLINE 1000

int get_line(char line [], int lim);
unsigned getbits(unsigned x, int p, int n);

int main()
{
    int i;
    unsigned int y;
    char line[MAXLINE]; // current line
    int len; // length of current line

    printf("Please enter an integer value 'x' at position 'p' with shift 'n':\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        y = getbits(line[0], line[1], line[2]);
        printf("%d\n", y);
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; i < (lim + 1) && (c = getchar()) != '\n' && c != EOF; i++)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = c;

    return i;
}

unsigned getbits(unsigned x, int p,int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
