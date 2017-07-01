#include <stdio.h>

/**** REMEMBER: CTRL + D = EOF */
int main()
{
    int c;

    printf("EOF is %d\n", EOF);

    while ((c = getchar ()) != EOF)
    {
        if (c != '\n')
        {
            putchar(c);
        }
        else
        {
            printf("\\n");
        }
        printf(": 'getchar != EOF' is %d\n", (c != EOF));
    }
    printf("'getchar != EOF' is %d\n", (c != EOF));

    return 0;
}
