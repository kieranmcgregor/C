#include <stdio.h>

int main()
{
    int c;

    printf("EOF is %d\n", EOF);

    while ((c = getchar ()) != EOF)
    {
        if (c == '@')
        {
            break;
        } else
        {
            putchar(c);
        }
    }
    printf("'getchar != EOF' is %d\n", (c != EOF));

    return 0;
}
