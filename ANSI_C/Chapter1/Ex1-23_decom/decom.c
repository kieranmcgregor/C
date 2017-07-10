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
    int i, state;
    int len; // length of line
    char line[MAXLINE]; // current line
    char clean_line[MAXLINE];

    state = OUT;

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        state = clean_comments(clean_line, line, len, state);

        printf("%s", clean_line);
        
        for (i = 0; i < MAXLINE; i++)
        {
            while (clean_line[i] != '\0')
            {
                clean_line[i] = '\0';
            }
            i = MAXLINE;
        }
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
    int i, clean_i, com_i;
    char com_sign[COMTYPE];

    clean_i = 0;
    com_i = 0;

    for (i = 0; i < len; i++)
    {
        if (state == OUT)
        {
            if (com_i >= 0 && com_i < 2)
            {
                if (line[i] == '/')
                {
                    com_sign[com_i] = line[i];
                    com_i++;
                }
                else if (line[i] == '*' && com_i > 0)
                {
                    com_sign[com_i] = line[i];
                    state = IN;
                    com_i++;
                }
                else
                {
                    if (com_i == 1)
                    {
                        clean_line[clean_i] = com_sign[com_i - 1];
                        com_i = 0;
                        clean_i++;
                    }
                    clean_line[clean_i] = line[i];
                    clean_i++;
                }
            }
        }
        else
        {
            if (line[i] == '*' && com_i > 1)
            {
                com_i--;
            }
            else if (line[i] == '/' && com_i < 2)
            {
                state = OUT;
                com_i--;
            }
            else if (line[i] != '*' && com_i < 2)
            {
                com_i++;
            }
        }

    }

    clean_line[clean_i] = '\0';

    return state;
}
