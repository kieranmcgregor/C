// TEST 1: a-f returns a, b, c, d, e, f
// TEST 2: a-d-f returns a, b, c, d, e, f
// TEST 3: A-F0-9 returns A, B, C, D, E, F'\n'0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// TEST 4: -a-f returns a, b, c, d, e, f
// TEST 5: --9 returns -, ., /, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// TEST 6: 9-- returns 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, /, ., -
// TEST 7: a-f--9 returns a, b, c, d, e, f'\n'-, ., /, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

#include <stdio.h>

#define MAXLINE 1000
#define SET_VAL 1

int get_line(char line[], int lim);
void expand(char line[], char exp_line[]);
void print_exp(char start_char, char end_char);

int main()
{
    char line[MAXLINE]; // current line
    int len; // length of current line
    char exp_line[MAXLINE]; // expanded line

    printf("Please enter a string for expansion:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);

        expand(line, exp_line);
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

void expand(char line[], char exp_line[])
{
    int i, start_set;
    char start_char;
    char end_char;

    for (i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == '-' && start_set != SET_VAL)
        {
            int prev_char = i - 1;
            int next_char = i + 1;

            if ((line[prev_char] >= 'a' && line[prev_char] <= 'z') || (line[prev_char] >= 'A' && line[prev_char] <= 'Z') || (line[prev_char] >= '0' && line[prev_char] <= '9'))
            {
                start_char = line[prev_char];
                start_set = SET_VAL;
            }
            else
            {
                if (line[next_char] == '-')
                {
                    start_char = line[i];
                    start_set = SET_VAL;
                }
            }
        }
        else if (start_set == SET_VAL)
        {
            if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= '0' && line[i] <= '9'))
            {
                int next_char = i + 1;

                end_char = line[i];

                if (line[next_char] != '-' && line[next_char] != '\n')
                {
                    start_set = !SET_VAL;
                    if(line[next_char + 1] == '-')
                    {
                        print_exp(start_char, end_char);
                    }
                }
                else if (line[next_char] == '-' && line[next_char + 1] == '-')
                {
                    print_exp(start_char, end_char);
                    start_char = line[next_char];
                }
            }
            else if (line[i] == '-' && line[i + 1] == '\n')
            {
                int prev_char = i - 1;

                if (line[prev_char] == '-')
                {
                    end_char = line[i];
                }
            }

        }
    }

    print_exp(start_char, end_char);
}

void print_exp(char start_char, char end_char)
{
    int i;

    for (i = start_char; i != end_char; (end_char > start_char) ? i++ : i--)
    {
        printf("%c, ", i);
    }
    printf("%c\n", i);
}
