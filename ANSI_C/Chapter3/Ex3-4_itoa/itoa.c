#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLINE 1000
#define BASE 10
#define NOSIGN 1
#define MAXXED 1

int get_line(char line[], int lim);
void a2i(int numbers[], char line[]);
void itoa(int n, char s[]);
void reverse(char s[]);
void printout(char s[]);

int main()
{
    int i;
    char line[MAXLINE]; // current line
    int len; // length of current line
    int numbers[MAXLINE]; // current integer inputs
    char s[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        a2i(numbers, line);
        printf("numbers: ");

        for (i = 0; numbers[i] != '\0'; i++)
        {
            if (numbers[i + 1] == '\0')
            {
                printf("%d\n", numbers[i]);
            }
            else
            {
                printf("%d, ", numbers[i]);
            }
        }

        for (i = 0; numbers[i] != '\0'; i++)
        {
            itoa(numbers[i], s);
            printout(s);
        }
    }
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; ((i <= lim) && ((c = getchar()) != EOF) && (c != '\n')); i++)
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

void a2i(int numbers[], char line[])
{
    int i, j, num_i, nums_i;
    char number[MAXLINE];
    int value;
    int sign;

    sign = NOSIGN;
    nums_i = 0;

    for (i = num_i = 0; line[i] != '\0'; i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            number[num_i++] = line[i] - '0';
        }
        else if (line[i] == '-')
        {
            sign = -NOSIGN;
        }
        else
        {
            for (j = value = 0; j < num_i; j++)
            {
                value += number[j] * pow(BASE, (num_i - (j + 1)));
                number[j] = '\0';
            }
            numbers[nums_i++] = value * sign;
        }
    }

    numbers[nums_i] = '\0';
}

void itoa(int n, char s[])
{
    int i, sign;
    int threshold;

    threshold = 0;

    if ((sign = n) < 0)
    {
        if (-n == n)
        {
            n = n - 1;
            threshold = MAXXED;
        }
        else
        {
            n = -n;
        }
    }

    i = 0;

    do
    {
        s[i++] = n % 10 + '0';

    }
    while((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }

    if (threshold == MAXXED)
    {
        s[0] = s[0] + 1;
    }

    s[i] = '\0';

    reverse(s);
}

void reverse(char s[])
{
    int temp, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void printout(char s[])
{
    int i;

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i + 1] == '\0')
        {
            printf("%c\n", s[i]);
        }
        else
        {
            printf("%c, ", s[i]);
        }
    }
}
