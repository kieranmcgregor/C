// TEST 1: '"\? "   ' returns
//      \'\"\\\? \"\t\'\n for escape line sequence
// TEST 2: 'This is an  escape" line?conversion returns
//      \'This is an\tescape\" line\?conversion\n for escape line sequence

#include <stdio.h>

#define MAXLINE 1000
#define IN 1

int get_line(char line[], int lim);
void escape(char escape_line[], char line[]);
void reversion(char reverted_line[], char escape_line[]);

int main()
{
    char line[MAXLINE]; // current line
    int len; // length of current line
    char escape_line[MAXLINE]; // current line with substituted escape characters
    char reverted_line[MAXLINE]; // escape_line reverted to norm

    printf("Please enter a string for conversion:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s\n", len, line);

        escape(escape_line, line);
        printf("%s\n\n", escape_line);

        reversion(reverted_line, escape_line);
        printf("Escaped line: %s\nReverted line :%sTrue line: %s\n", escape_line, reverted_line, line);

        printf("Please enter a string for conversion:\n*Press 'CTRL + d' to exit*\n");
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; (i < lim + 1) && ((c = getchar()) != EOF) && (c != '\n'); i++)
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

void escape(char escape_line[], char line[])
{
    int i, ei;

    ei = 0;

    for (i = 0; line[i] != '\0'; i++)
    {
        switch (line[i])
        {
            case '\n':
                escape_line[ei++] = '\\';
                escape_line[ei++] = 'n';
                break;

            case '\t':
                escape_line[ei++] = '\\';
                escape_line[ei++] = 't';
                break;

            case '\r':
                escape_line[ei++] = '\\';
                escape_line[ei++] = 'r';
                break;

            case '\v':
                escape_line[ei++] = '\\';
                escape_line[ei++] = 'v';
                break;

            case '\\':
                escape_line[ei++] = '\\';
                escape_line[ei++] = '\\';
                break;

            case '\?':
                escape_line[ei++] = '\\';
                escape_line[ei++] = '?';
                break;

            case '\'':
                escape_line[ei++] = '\\';
                escape_line[ei++] = '\'';
                break;

            case '\"':
                escape_line[ei++] = '\\';
                escape_line[ei++] = '\"';
                break;

            default:
                escape_line[ei++] = line[i];
                break;
        }
    }

    escape_line[ei] = '\0';
}

void reversion(char reverted_line[], char escape_line[])
{
    int i, ri;
    int escape_char;

    ri = 0;
    escape_char = !IN;

    for (i = 0; escape_line[i] != '\0'; i++)
    {
        if ( (escape_line[i] == '\\') && (escape_char != IN) )
        {
            escape_char = IN;
        }
        else if (escape_char == IN)
        {
            escape_char = !IN;

            switch (escape_line[i])
            {
                case 'n':
                    reverted_line[ri++] = '\n';
                    break;

                case 't':
                    reverted_line[ri++] = '\t';
                    break;

                case 'r':
                    reverted_line[ri++] = '\r';
                    break;

                case 'v':
                    reverted_line[ri++] = '\v';
                    break;

                case '\\':
                    reverted_line[ri++] = '\\';
                    break;

                case '?':
                    reverted_line[ri++] = '\?';
                    break;

                case '\'':
                    reverted_line[ri++] = '\'';
                    break;

                case '\"':
                    reverted_line[ri++] = '\"';
                    break;

                default:
                    reverted_line[ri++] = '\\';
                    reverted_line[ri++] = escape_line[i];
                    break;
            }
        }
        else
        {
            reverted_line[ri++] = escape_line[i];
        }
    }

    reverted_line[ri] = '\0';
}
