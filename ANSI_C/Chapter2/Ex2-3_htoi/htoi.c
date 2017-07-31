// Test 1: abcdefABCDEFgGhHiI (returns value for abcdefABCDEF, 188900977659375)
// Test 2: 0x1f4e6a == 1f4e6a (returns same int value for both)
// Test 3: 56789abcdefabcdef (returns out of range error)
// Test 4: -100 (returns -256)

#include <stdio.h>
#include <math.h>

/**** REMEMBER: CTRL + D = EOF */
#define MAXLINE 1000

int get_line(char line[], int lim);
long long htoi(int len, char line[]);

int main()
{
    char line[MAXLINE]; // current line
    int len; // length of current line
    long long convint; // integer value of converted hexidecimal

    printf("Please enter a hexadecimal number (0-F) to convert to an integer (0-9)\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d chars in %s\n", len, line);
        convint = htoi(len, line);
        if (convint != '\0')
        {
            printf("hexidecimal value %s equals the integer value %lld\n", line, convint);
        }
    }
    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; (i < lim + 1) && (c = getchar()) != '\n' && c != EOF; i++)
    {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || c == '-')
        {
            line[i] = c;
        }
        else if (((c == 'X') || (c == 'x')) && i == 1 && line[i - 1] == '0')
        {
            line[i] = c;
        }
        else
        {
            printf("Invalid hexadecimal value '%c' entered, skipping character\n", c);
            i--;
        }
    }

    line[i] = '\0';

    return i;
}

long long htoi(int len, char line[])
{
    int i;
    long long convint = 0;
    long long last_val;

    for (i = 0; i < len; i++)
    {
        last_val = convint;
        long long pos_val = pow(16, (len - (i + 1)));

        if (line[i] >= '0' && line[i] <= '9')
        {
            convint += ((line[i] - '0') * pos_val);
        }
        else if (line[i] >= 'a' && line[i] <= 'f')
        {
            convint += (((line[i] - 'a') + 10) * pos_val);
        }
        else if (line[i] >= 'A' && line[i] <= 'F')
        {
            convint += (((line[i] - 'A') + 10) * pos_val);
        }

        if (last_val > convint)
        {
            printf("Value to large to convert, insufficient memory\n");
            return '\0';
        }
    }

    if (line[0] == '-')
    {
        convint = -convint;
    }

    return convint;
}
