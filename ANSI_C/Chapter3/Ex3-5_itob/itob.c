#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAXLINE 1000
#define BASE 10
#define NOSIGN 1
#define MAXXED 1

int get_line(char line[], int lim);
void a2i(int numbers[], char line[]);
void itob(int n, char s[], int base);
void reverse(char s[]);
void printout(char s[]);

int main()
{
    int i;
    char line[MAXLINE]; // current line
    int len; // length of current line
    int numbers[MAXLINE]; // current integer inputs
    char s[MAXLINE];

    printf("Please enter a base 10 integer for conversion and a base to convert the integer to\n");
    printf("separated by a space:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        a2i(numbers, line);
        printf("numbers: %d, %d\n", numbers[0], numbers[1]);

        itob(numbers[0], s, numbers[1]);
        printf("String: %s\n", s);
        printout(s);
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
        if (nums_i < 2)
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

                if (nums_i > 0 && value > 36)
                {
                    printf("Base value larger than 36, using base 36 for conversion\n");
                    value = 36;
                }

                numbers[nums_i++] = value * sign;
            }
        }
        else
        {
            printf("Too many values entered taking first two values\n");
            break;
        }
    }
    if (nums_i < 2)
    {
        printf("Too few values entered using default base 10\n");
        numbers[nums_i++] = BASE;
    }
    numbers[nums_i] = '\0';
}

void itob(int n, char s[], int base)
{
    int i, sign, m;
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
        m = n % base;

        if (m > 9)
        {
            s[i++] = m - 10 + 'A';
        }
        else
        {
            s[i++] = m + '0';
        }
    }
    while((n /= base) > 0);

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
