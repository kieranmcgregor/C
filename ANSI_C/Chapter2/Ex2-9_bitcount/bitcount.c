#include <stdio.h>
#include <math.h>

#define MAXLINE 1000
#define MAXIN 1
#define GTZ 0

int get_line(char line[], int lim);
void get_values(int numbers[], char line[], int len);
int bitcount(unsigned x);

int main()
{
    int len; // length of current line
    char line[MAXLINE]; // current line
    int numbers[MAXIN]; // current input values
    unsigned answer;

    printf("Please enter an integer value, 'x', for bit counting:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        get_values(numbers, line, len);
        answer = bitcount(numbers[0]);
        printf("%d\n\n", answer);
        printf("Please enter an integer value, 'x', for bit counting:\n*Press 'CTRL + d' to exit*\n");
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

int bitcount(unsigned x)
{
    // b++> 1000 & 0111 == 0000, b == 1
    // b++> 0011 & 0010 == 0010 b++> 0010 & 0001 == 0000, b == 2
    // b++> 0111 & 0110 == 0110 b++> 0110 & 0101 == 0100 b++> 0100 & 0011 = 0000, b == 3
    // b++> 1111 & 1110 == 1110 b++> 1110 & 1101 == 1100 b++> 1100 & 1011 = 1000 b++> 1000 & 0111 == 0000, b == 4
    int b;

    for (b = 0; x != 0; x &= (x - 1))
    {
        printf("%d\n", x);
        b++;
    }

    return b;
}
