#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000

int get_line(char line[], int lim);

int main() {
    int len; //length of current line
    char line[MAXLINE];

    printf("Please enter a string: *Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);
    }

    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; i < lim + 1; i++)
    {
        if((c = getchar()) != '\n')
        {
            if(c != EOF)
            {
                line[i] = c;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
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
