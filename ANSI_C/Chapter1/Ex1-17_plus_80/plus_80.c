#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000

int get_line(char line[], int lim);

int main()
{
    int len; // length of current line
    char line[MAXLINE]; // current line input

    printf("Please enter a string:\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (len > 80)
        {
            printf("%s\n", line);
        }
        else
        {
            printf("\n");
        }
    }
    return 0;
}

// read a line into s, return length
int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; i < (lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = '\0';

    return i;
}
