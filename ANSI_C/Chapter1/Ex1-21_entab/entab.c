// test line 1: hello	this	is    a    test
// test line 2: hello  	this  	is another	test

#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000
#define TABSPACE 8
#define IN 1
#define OUT 0

int get_line(char line[], int lim);

int main()
{
    int i;
    int len; // length of line
    char line[MAXLINE]; // current line

    printf("Please enter a string:\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d\n%s\n", len, line);

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
    int spc_i; // spaces index
    int col; // current column position
    char spaces[MAXLINE];

    col = 0;
    spc_i = 0;

    for (i = 0; ((c = getchar()) != EOF) && (c != '\n') && (i != lim); i++)
    {
        // printf("for: %c %d - %s\n", c, i, line);
        if (c == ' ')
        {
            // printf("if-b4: %c %d - %s\n", c, i, line);
            spaces[spc_i] = c;
            spc_i++;
            i--;
            // printf("if-aft: %c %d - %s\n", c, i, line);
        }
        else if (spc_i > 0)
        {
            if (c != '\t')
            {
                if (((col + spc_i) % TABSPACE) == 0)
                {
                    line[i] = '\t';
                    i++;
                }
                else
                {
                    for (int temp_i = 0; temp_i < spc_i; temp_i++)
                    {
                        line[i] = ' ';
                        i++;
                    }
                }
            }

            line[i] = c;

            col += spc_i;
            spc_i = 0;
            // printf("elif: %c %d - %s\n", c, i, line);
        }
        else
        {
            // printf("else: %c %d - %s\n", c, i, line);
            line[i] = c;
            col++;
        }
    }

    if (c == '\n')
    {
        line[i] = c;
        i++;
        col++;
    }

    line[i] = '\0';

    printf("%d %d\n%s\n", col, i, line);

    return i;
}
