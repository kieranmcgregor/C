#include <stdio.h>
// removes comments from a C program

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000
#define COMTYPE 2
#define IN 1
#define OUT 0

int get_line(char line[], int lim);
int clean_comments(char clean_line[], char line[], int len, int state);

int main()
{
    int state;
    int len; // length of line
    char line[MAXLINE]; // current line
    char clean_line[MAXLINE];

    state = OUT;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        state = clean_comments(clean_line, line, len, state);
        printf("%d\n%s", len, clean_line);
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

int clean_comments(char clean_line[], char line[], int len, int state)
{
    int i, com_i;
    char com_sign[COMTYPE];

    com_i = 0;

    for (i = 0; i < len; i++)
    {
        if ((line[i] == '/' || ((com_sign > 0) && (line[i] == '*'))) && state == OUT)
        {
            com_sign[com_i] = line[i];
            com_i++;
        }
    }
    return 0;
}
