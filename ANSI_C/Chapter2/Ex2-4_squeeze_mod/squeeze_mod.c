#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim);
void squeeze(char line[], char c);

int main()
{
    char line[MAXLINE]; // current line input
    char del_line[MAXLINE]; // string to be deleted from line
    int len; // length of current line
    int del_len; // length of deletion line

    printf("Please enter a string: *Press 'CTRL + d' to exit*\n");

    while ( (len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s\n", len, line);

        printf("Please enter a string for deletion from first line: *Press 'CTRL + d' to exit*\n");
        del_len = get_line(del_line, MAXLINE);

        printf("%d, '%s'\n", del_len, del_line);

        for (int i = 0; del_line[i] != '\0'; i++)
        {
            squeeze(line, del_line[i]);
        }

        printf("%s\n\n", line);

        printf("Please enter a string: *Press 'CTRL + d' to exit*\n");
    }

    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; (i < lim + 1) && ((c = getchar()) != '\n') && (c != EOF); i++)
    {
        line[i] = c;
    }

    line[i] = '\0';

    return i;
}

void squeeze(char line[], char c)
{
    int i, j;

    for (i = j = 0; line[i] != '\0'; i++)
    {
        if (line[i] != c)
        {
            line[j++] = line[i];
        }
    }

    line[j] = '\0';
}
