#include <stdio.h>
/* checks for basis syntax (i.e. unbalanced brackets, braces & parentheses,
quotes, both single and double, excape sequences and comments) in a C program */

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000

int get_line(char line[], int lim);

int main()
{
    int len; // length of current line
    char line[MAXLINE]; // current line of chars

    printf("Please enter a string:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d\n%s", len, line);
    }
    return 0;
}


int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; ((c = getchar()) != EOF) && (c != '\n') && (i != lim); i++)
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
