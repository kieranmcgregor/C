#include <stdio.h>

int main ()
{
    #define LOWER 0
    #define UPPER 300
    #define STEP 20

    float fahr, celsius;

    fahr = LOWER;
    printf("Fahrenheit to Celsius Converter\nF\tC\n");

    while (fahr <= UPPER)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);

        fahr += STEP;
    }

    return 0;
}
