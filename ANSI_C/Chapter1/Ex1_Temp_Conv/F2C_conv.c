#include <stdio.h>

int main ()
{
    #define LOWER 0
    #define UPPER 300
    #define STEP 20

    float fahr;

    printf("C\tF\n");

    for (float celsius = LOWER; celsius < UPPER; celsius += STEP)
    {
        fahr = (celsius * (9.0/5.0)) + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
    }

    return 0;
}
