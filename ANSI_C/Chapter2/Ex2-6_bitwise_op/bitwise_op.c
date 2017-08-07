#include <stdio.h>
#include <math.h>

#define MAXLINE 1000
#define MAXIN 4

int get_line(char line [], int lim);
void get_values(int numbers[], char line[], int len);
unsigned getbits(unsigned x, int p, int n, unsigned y);

int main()
{
    int i;
    unsigned int answer;
    char line[MAXLINE]; // current line
    int len; // length of current line
    int numbers[MAXIN]; // numbers in current line

    printf("Please enter an integer value 'x' for setting, the start position 'p'\n");
    printf("(0 - 3, right to left), the number of bits 'n' and an integer value 'y'\n");
    printf("for getting all separated by spaces:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        get_values(numbers, line, len);

        answer = getbits(numbers[0], numbers[1], numbers[2], numbers[3]);
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

    for (i = 0; i < (lim + 1) && (c = getchar()) != '\n' && c != EOF; i++)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        i++;
    }

    line[i] = c;

    return i;
}

void get_values(int numbers[], char line[], int len)
{
    int i, j, nums_i, num_i, c;
    int num;
    int base = 10;
    int value, exponent;
    int number[MAXLINE];

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
        else
        {
            for (j = 0; j < num_i; j++)
            {
                exponent = (num_i - (j + 1));
                value += (number[j]) * pow(base, exponent);
                number[j] = '\0';
            }

            if (nums_i < MAXIN)
            {
                numbers[nums_i++] = value;
                value = 0;
            }
            else
            {
                printf("Too many inputs, accepting first four values ");

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

unsigned getbits(unsigned x, int p, int n, unsigned y)
{
    unsigned z;
    unsigned mask;

    z = x;
    mask = 0;

    if (p < 0)
    {
        p = 0;
        printf("Value for 'p' less than 0, p equals %d\n", p);
    }
    else if (p > 3)
    {
        p = p % 4;
        printf("Value for 'p' greater than 3, p equals %d\n", p);
    }

    if (n < 1)
    {
        n = 1;
        printf("Value for 'n' less than 1, n equals %d\n", n);
    }
    else if (n > 4)
    {
        n = ((n - 1) % 4) + 1;
        printf("Value for 'n' greater than 4, n equals %d\n", n);
    }

    printf("x = %d, p = %d, n = %d, y = %d\n", x, p, n, y);

    if (n < (p + 1))
    {
        // printf("0. %d\n", mask);
        mask = ~(~mask << n);
        // printf("1. %d\n", mask);
        mask = ~(mask << ((p + 1) - n));
        // printf("2. %d\n", mask);
        x = x & mask;
        // printf("3. %d\n", x);

        mask = 0;
        // printf("4. %d\n", mask);
        mask = ~(~mask << n);
        // printf("5. %d\n", mask);
        z = y & mask;
        // printf("6. %d\n", z);
        z = z << ((p + 1) - n);
        // printf("7. %d\n", z);

        x = x | z;
        // printf("8. %d\n", x);

        return x;
    }
    else
    {
        printf("Invalid entry, 'n' cannot be larger than 'p + 1'.\n");
        return 0;
    }
}
