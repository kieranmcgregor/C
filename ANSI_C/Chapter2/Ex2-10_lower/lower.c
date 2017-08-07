#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim);
void lower(char low_line[], char line[], int len);

int main()
{
    char line[MAXLINE]; // current line
    int len; // length of current line
    char low_line[MAXLINE]; // lower case of current line

    printf("Please enter a string for conversion to lower case:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s\n", len, line);

        lower(low_line, line, len);
        printf("%s\n", low_line);

        printf("Please enter a string for conversion to lower case:\n*Press 'CTRL + d' to exit*\n");
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; (i < (lim + 1)) && ((c = getchar()) != EOF) && (c != '\n'); i++)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i++] = c;
    }

    line[i] = '\0';

    return i;
}

void lower(char low_line[], char line[], int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        (line[i] >= 'A' && line[i] <= 'Z') ? (low_line[i] = ((line[i] - 'A') + 'a')) : (low_line[i] = line[i]);
    }
}
