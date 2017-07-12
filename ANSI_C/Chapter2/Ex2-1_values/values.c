#include <stdio.h>

void calculate_char(char c);
void calculate_int(int i);

int main()
{
    char c;
    signed char sc;
    short int s;
    unsigned short int us;
    int i;
    unsigned int ui;
    long int l;
    unsigned long int ul;

    c = sc = '1';
    s = us = i = ui = l = ul = 1;

    printf("Let's go!\nchar:\n");
    calculate_char(c);
    printf("signed char:\n");
    calculate_char(sc);

    printf("short int:\n");
    calculate_int(s);
    printf("unsigned short int:\n");
    calculate_int(us);
    printf("int:\n");
    calculate_int(i);
    printf("unsigned int:\n");
    calculate_int(ui);
    printf("long int:\n");
    calculate_int(l);
    printf("unsigned long int:\n");
    calculate_int(ul);
}

void calculate_char(char c)
{
    while (c > 0)
    {
        c++;
    }
    printf("%c %c\n", c, (c - 1));
}

void calculate_int(int i)
{
    while (i > 0)
    {
        i++;
    }
    printf("%d %d\n", i, (i - 1));
}
