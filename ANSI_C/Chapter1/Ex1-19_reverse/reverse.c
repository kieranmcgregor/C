#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000

int get_line(char line[], int lim);
void reverser(char line[], int len);

int main()
{
    int i;
    int len; // length of line
    char line[MAXLINE]; //current line

    printf("Please enter a string:\n");

    while((len = get_line(line, MAXLINE)) > 0)
    {
        reverser(line, len);
    }

    return 0;
}

int get_line(char line[], int lim)
{
    int c, i;

    for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
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

void reverser(char line[], int len)
{
    int i;
    for (i = 0; i < (len); i++)
    {
        printf("%c", line[(len - 1) - i]);
    }
    printf("\n");
}
