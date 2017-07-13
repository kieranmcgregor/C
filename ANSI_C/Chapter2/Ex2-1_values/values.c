#include <stdio.h>

void calculate_char(char c);
long long power(int base, int exp);

int main()
{
    unsigned char uc;
    char c;
    short s;
    unsigned short us;
    int i;
    unsigned int ui;
    long long l;
    unsigned long long ul;

    long long temp_l;
    int idx, temp_i, temp_c;

    uc = c = 1;
    s = i = l = us = ui = ul = 1;
    temp_i = temp_c = temp_l = 0;

    printf("Let's go!\n\nchar:\n");
    for (idx = 1; c > 0; idx++)
    {
        temp_c = c = power(2, idx) - 1;
        c++;
    }
    printf("%d bits with range\n%d to %d\n\n", idx, c, temp_c);

    printf("short int:\n");
    for (idx = 1; s > 0; idx++)
    {
        temp_i = s = power(2, idx) - 1;
        s++;
    }
    printf("%d bits with range\n%d to %d\n\n", idx, s, temp_i);

    printf("int:\n");
    for (idx = 1; i > 0; idx++)
    {
        temp_i = i = power(2, idx) - 1;
        i++;
    }
    printf("%d bits with range\n%d to %d\n\n", idx, i, temp_i);


    printf("long int:\n");
    for (idx = 1; l > 0; idx++)
    {
        temp_l = l = power(2, idx) - 1;
        l++;
    }
    printf("%d bits with range\n%lld to %lld\n\n", idx, l, temp_l);

    printf("unsigned char:\n");
    for (idx = 1; uc > 0; idx++)
    {
        temp_c = uc = power(2, idx) - 1;
        uc++;
    }
    printf("%d bits with range\n%d to %d\n\n", (idx - 1), uc, temp_c);

    printf("unsigned short int:\n");
    for (idx = 1; us > 0; idx++)
    {
        temp_i = us = power(2, idx) - 1;
        us++;
    }
    printf("%d bits with range\n%u to %u\n\n", (idx - 1), us, temp_i);

    printf("unsigned int:\n");
    for (idx = 1; ui > 0; idx++)
    {
        temp_i = ui = power(2, idx) - 1;
        ui++;
    }
    printf("%d bits with range\n%u to %u\n\n", (idx - 1), ui, temp_i);

    printf("unsigned long int:\n");
    for (idx = 1; ul > 0; idx++)
    {
        temp_l = ul = power(2, idx) - 1;
        ul++;
    }
    printf("%d bits with range\n%llu to %llu\n", (idx - 1), ul, temp_l);
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
