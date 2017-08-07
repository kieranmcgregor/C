#include <stdio.h>
#include <math.h>

#define MAXLINE 1000
#define MAXIN 3
#define GTZ 0

int get_line(char line[], int lim);
void get_values(int numbers[], char line[], int len);
unsigned rightrot(unsigned x, int n);

int main()
{
    int len; // length of current line
    char line[MAXLINE]; // current line
    int numbers[MAXIN]; // current input values
    unsigned answer;

    printf("Please enter an integer value, 'x', to be inverted, the start position\n");
    printf("(0 - 3, right to left), 'p' and the number of bits, 'n', for inversion,\n");
    printf("separated by spaces:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        get_values(numbers, line, len);
        answer = rightrot(numbers[0], numbers[1]);
        printf("%d\n\n", answer);
        printf("Please enter an integer value 'x' for setting, the start position 'p'\n");
        printf("(0 - 3, right to left), the number of bits 'n' and an integer value 'y'\n");
        printf("for getting all separated by spaces:\n*Press 'CTRL + d' to exit*\n");
    }

    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;

    for (i = 0; (i < (lim + 1)) && ((c = getchar()) != EOF) && (c != '\n'); i++)
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

void get_values(int numbers[], char line[], int len)
{
    int i, j, nums_i, num_i;
    int num;
    int value, exponent;
    int number[MAXLINE];

    int sign = GTZ;
    int base = 10;

    nums_i = 0;
    num_i = 0;
    value = 0;

    for (i = 0; i < len; i++)
    {

        if (line[i] >= '0' && line[i] <= '9')
        {
            num = line[i] - '0';
            number[num_i++] = num;
        }
        else if (line[i] == '-')
        {
            sign = !GTZ;
        }
        else
        {
            for (j = 0; j < num_i; j++)
            {
                exponent = (num_i - (j + 1));
                value += (number[j]) * pow(base, exponent);
                number[j] = '\0';
            }

            if (sign)
            {
                value = -value;
                sign = GTZ;
            }

            if (nums_i < MAXIN)
            {
                numbers[nums_i++] = value;
                value = 0;
            }
            else
            {
                printf("Too many inputs, accepting first %d values ", MAXIN);

                for (j = 0; j < MAXIN; j++)
                {
                    if (j == (MAXIN - 1))
                    {
                        printf("%d.\n", numbers[j]);
                    }
                    else
                    {
                        printf("%d, ", numbers[j]);
                    }
                }
                break;
            }
        }
    }
}

unsigned rightrot(unsigned x, int n)
{
    if (n < 1)
    {
        n = 1;
        printf("Value for 'n' less than 1, n set to %d\n", n);
    }
    else if (n > 4)
    {
        n = ((n - 1) % 4) + 1;
        printf("Value for 'n' greater than 4, n set to %d\n", n);
    }

    printf("x = %d, n = %d\n", x, n);

    return (x >> n) | ((x & ~(~mask << n)) << (4 - n));
}
