#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
// test string 1: 'hello    this	is    a test    '
// test string 2: ' '
#define IN 1
#define OUT 0
#define MAXLINE 1000

int get_line(char line[], int lim);
void clean_tail(int dlen, char dirty[], char clean[]);

int main()
{
    int j;
    int len; // length of current string
    char line[MAXLINE];
    char clean[MAXLINE];

    printf("Please enter a string:\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        clean_tail(len, line, clean);
    }

    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < (lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';

    return i;
}

void clean_tail(int dlen, char dirty[], char clean[])
{
    int i, ws_i, clean_i, state;
    char ws[MAXLINE];

    ws_i = 0;
    clean_i = 0;
    state = OUT;

    for (i = 0; i < (dlen - 1); i++)
    {
        if (dirty[i] == ' ' || dirty[i] == '\t')
        {
            ws[ws_i] = dirty[i];
            state = OUT;
            ws_i++;
        }
        else if (dirty[i] == '\n' && state == OUT)
        {
            clean[clean_i] = '\n';
            clean_i++;
        }
        else if (i > 0 && state == OUT)
        {
            for (int ti = 0; ti < ws_i; ti++)
            {
                clean[clean_i] = ws[ti];
                clean_i++;
            }

            ws_i = 0;

            clean[clean_i] = dirty[i];
            clean_i++;

            state = IN;
        }
        else
        {
            clean[clean_i] = dirty[i];
            clean_i++;
            state = IN;
        }
    }
    clean[clean_i] = '\0';
    printf("%s\n", clean);
}
