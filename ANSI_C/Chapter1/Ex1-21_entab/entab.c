// test line 1: hello	this	is    a    test
// test line 2: hello  	this  	is another	test
// test line 3: 12345678                this is 16 spaces after 8 characters
// test line 4: 12345678               this is 15 spaces after 8 characters
// test line 5: 12345678         this is 9 spaces after 8 characters

/* This program provides preference to tabs in the case of a single space that
would reach a tabstop. To change this behaviour to provide preference solely
to single spaces change line 77 from:

if (((col + spc_i) % TABSPACE) == 0)

to:

if ((spc_i > 1) && (((col + spc_i) % TABSPACE) == 0)) */

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
    char spaces[MAXLINE]; // current string of white space

    col = 0;
    spc_i = 0;

    for (i = 0; ((c = getchar()) != EOF) && (c != '\n') && (i != lim); i++)
    {
        if (c == ' ')
        {
            spaces[spc_i] = c;
            spc_i++;
            i--;
        }
        else if (spc_i > 0)
        {
            if (c != '\t')
            {
                while (spc_i > TABSPACE)
                {
                    line[i] = '\t';
                    i++;
                    col += TABSPACE;
                    spc_i -= TABSPACE;
                }

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

            col += (spc_i + 1);
            spc_i = 0;
        }
        else
        {
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

    return i;
}
