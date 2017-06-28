#include <stdio.h>

main()
{
    int c;

    printf("Please type a string:\n");

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            printf("\\t");
        }
        else if (c == '\b')
        {
            printf("\\b");
        }
        else if (c == '\\')
        {
            printf("\\\\");

        }
        else if (c == '@')
        {
            break;
        }
        else
        {
            putchar(c);
        }
    }
}
