#include <stdio.h>

void calculate_char(char c);
long long power(int base, int exp);

int main()
{
    char c;
    signed char sc;
    short s;
    unsigned short us;
    int i;
    unsigned int ui;
    long long l;
    unsigned long long ul;

    long long temp_l;
    int idx, temp_i;

    s = sc = 1;
    i = l = us = ui = ul = 1;
    temp_i = temp_l = 0;

    printf("Let's go!\nchar:\n");
    calculate_char(c);
    printf("signed char:\n");
    calculate_char(sc);

    printf("short int:\n");
    for (idx = 1; s > 0; idx++)
    {
        temp_i = s = ((power(2, idx) / 2) - 1);
        s++;
    }
    printf("%d %d %d\n", s, (idx - 1), temp_i);

    printf("int:\n");
    for (idx = 1; i > 0; idx++)
    {
        temp_i = i = ((power(2, idx) / 2) - 1);
        i++;
    }
    printf("%d %d %d\n", i, (idx - 1), temp_i);

    printf("long int:\n");
    for (idx = 1; l > 0; idx++)
    {
        temp_l = l = ((power(2, idx) / 2) - 1);
        l++;
    }
    printf("%lld %d %lld\n", l, (idx - 1), temp_l);

    printf("unsigned short int:\n");
    for (idx = 1; us > 0; idx++)
    {
        temp_i = us = (power(2, idx) - 1);
        us++;
    }
    printf("%u %d %u\n", us, (idx - 1), temp_i);

    printf("unsigned int:\n");
    for (idx = 1; ui > 0; idx++)
    {
        temp_i = ui = (power(2, idx) - 1);
        ui++;
    }
    printf("%u %d %u\n", ui, (idx - 1), temp_i);

    printf("unsigned long int:\n");
    for (idx = 1; ul > 0; idx++)
    {
        temp_l = ul = (power(2, idx) - 1);
        ul++;
    }
    printf("%llu %d %llu\n", ul, (idx - 1), temp_l);
}

void calculate_char(char c)
{
    while (c > 0)
    {
        c++;
    }
    printf("%c %c\n", c, (c - 1));
}

long long power(int base, int exponent)
{
    if (exponent == 0)
    {
        return 1;
    }
    else
    {
        return (base * power(base, (exponent - 1)));
    }
}
