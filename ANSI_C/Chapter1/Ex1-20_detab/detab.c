// test line 1: hello	this	is    a    test
// test line 2: hello  	this  	is another	test

#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000
#define TABSPACE 8

int get_line(char line[], int lim);

int main()
{
    int i;
    int len;
    char line[MAXLINE];

    printf("Please enter a string:\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d - %s\n", len, line);

        for (i = 0; i < len; i++)
        {
            line[i] = '\0';
        }
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; ((c = getchar()) != EOF) && (c != '\n') && (i != lim); i++)
    {
        if (c == '\t')
        {
            while ((i % TABSPACE) != 0)
            {
                line[i] = ' ';
                i++;
            }
            i--;
        }
        else
        {
            line[i] = c;
        }
    }
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';

    return i;
}
