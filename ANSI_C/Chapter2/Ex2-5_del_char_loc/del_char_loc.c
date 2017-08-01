#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int lim);
int squeeze(char line[], char c, int loc);

int main()
{
    char line[MAXLINE]; // current line input
    char del_line[MAXLINE]; // string to be deleted from line
    int len; // length of current line
    int del_len; // length of deletion line
    int loc; //location of first instance if del_line char deletion
    int i;

    printf("Please enter a string: *Press 'CTRL + d' to exit*\n");

    while ( (len = get_line(line, MAXLINE)) > 0)
    {
        loc = -1;
        i = 0;
        
        printf("%d, %s\n", len, line);

        printf("Please enter a string for deletion from first line: *Press 'CTRL + d' to exit*\n");
        del_len = get_line(del_line, MAXLINE);

        printf("%d, '%s'\n", del_len, del_line);

        while (i < del_len)
        {
            for (i = 0; del_line[i] != '\0'; i++)
            {
                loc = squeeze(line, del_line[i], loc);
            }
        }

        printf("%d\n\n", loc);

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

int squeeze(char line[], char c, int loc)
{
    int i;

    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == c)
        {
            if (loc > i || loc == -1)
            {
                loc = i;
            }
        }
    }

    return loc;
}
