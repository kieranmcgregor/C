#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXLINE 1000
#define MAXSEARCH 1
#define NOSIGN 0
#define BASE 10
#define TEST_ROUNDS 100000

int get_line(char line[], int lim);
void clear_line(char line[], int len);
int get_values(int numbers[], char line[], int len, int lim);

int binsearch(int searchval, int numbers[], int num_len);
int altbinsearch(int searchval, int numbers[], int num_len);

double bintimer(int searchval, int numbers[], int num_len);
double alttimer(int searchval, int numbers[], int num_len);

int main()
{
    char line[MAXLINE]; //current line
    int len; // length of current line
    int numbers[MAXLINE]; // array of numbers extracted from line
    int num_len; // length of numbers array
    int searchval[MAXSEARCH];
    int pos; // index of search value
    int i;
    double tot_time1, tot_time2;

    printf("Please enter an array of integers in increasing order separated by spaces:\n*Press 'CTRL + d' to exit*\n");

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);
        num_len = get_values(numbers, line, len, MAXLINE);
        printf("%d value%s in %s\n", num_len, ((num_len == 1) ? "" : "s"), line);

        printf("Please enter an integer value to check if it is in the array: ");
        clear_line(line, len);
        len = get_line(line, MAXLINE);
        get_values(searchval, line, len, MAXSEARCH);

        pos = binsearch(searchval[0], numbers, num_len);
        if (pos >= 0)
        {
            printf("Value %d found at index %d in numbers array.\n\n", searchval[0], pos);
        }
        else
        {
            printf("Value not found in numbers array.\n\n");
        }

        pos = altbinsearch(searchval[0], numbers, num_len);
        if (pos >= 0)
        {
            printf("Value %d found at index %d in numbers array.\n\n", searchval[0], pos);
        }
        else
        {
            printf("Value not found in numbers array.\n\n");
        }

        tot_time1 = tot_time2 = 0;

        for (i = 0; i < TEST_ROUNDS; i++)
        {
            tot_time1 += bintimer(searchval[0], numbers, num_len);
            tot_time2 += alttimer(searchval[0], numbers, num_len);
        }

        printf("binsearch took %f to execute %d times.\n", tot_time1, TEST_ROUNDS);
        printf("altbinsearch took %f to execute %d times.\n", tot_time2, TEST_ROUNDS);

        printf("Please enter an array of integers in increasing order separated by spaces:\n*Press 'CTRL + d' to exit*\n");
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

void clear_line(char line[], int len)
{
    int i;

    for (i = len; i > 0; i--)
    {
        line[i] = '\0';
    }
}

int get_values(int numbers[], char line[], int len, int lim)
{
    int i, j, num_i, nums_i;
    char number[MAXLINE]; // current number
    int sign; // sign of current number
    int value; // value of current number

    num_i = 0;
    nums_i = 0;
    sign = NOSIGN;
    value = 0;

    for (i = 0; i < len; i++)
    {
        if (line[i] >= '0' && line[i] <= '9')
        {
            number[num_i++] = (line[i] - '0');
        }
        else if ((line[i] == '-') && (num_i == 0))
        {
            sign = !NOSIGN;
        }
        else
        {
            for (j = 0; j < num_i; j++)
            {
                value += number[j] * (pow(BASE, (num_i - (j + 1))) );
                number[j] = '\0';
            }

            if (sign)
            {
                value = -value;
            }

            if (nums_i < lim)
            {
                numbers[nums_i++] = value;
                value = num_i = 0;
            }
            else
            {
                printf("Too many values entered, using first %d value%s.\n", lim, (lim == 1 ? "" : "s"));
                return nums_i;
            }
        }
    }

    return nums_i;
}

int binsearch(int searchval, int numbers[], int num_len)
{
    int low, high, mid;

    low = 0;
    high = num_len - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (searchval < numbers[mid])
        {
            high = mid - 1;
        }
        else if (searchval > numbers[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return -1;
}

int altbinsearch(int searchval, int numbers[], int num_len)
{
    int low, high, mid;

    low = 0;
    high = num_len - 1;
    mid = (low + high) / 2;

    while (searchval != numbers[mid] && low <= high)
    {
        if (searchval < numbers[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

        mid = (low + high) / 2;
    }

    if (low > high)
    {
        return -1;
    }
    else
    {
        return mid;
    }
}

double bintimer(int searchval, int numbers[], int num_len)
{
    int pos; // position of searched integer value
    clock_t begin; // begin program timing
    clock_t end; // end program timing
    double time_taken;

    begin = clock();
    pos = binsearch(searchval, numbers, num_len);
    end = clock();
    time_taken = (double)(end - begin) / CLOCKS_PER_SEC;

    return time_taken;
}

double alttimer(int searchval, int numbers[], int num_len)
{
    int pos; // position of searched integer value
    clock_t begin; // begin program timing
    clock_t end; // end program timing
    double time_taken;

    begin = clock();
    pos = altbinsearch(searchval, numbers, num_len);
    end = clock();
    time_taken = (double)(end - begin) / CLOCKS_PER_SEC;

    return time_taken;
}
