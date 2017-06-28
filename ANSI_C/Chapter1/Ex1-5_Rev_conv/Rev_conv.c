#include <stdio.h>

int main ()
{
    #define LOWER 0
    #define UPPER 300
    #define STEP 20

    float fahr, celsius;

    printf("\nFahrenheit to Celsius Converter\nF\tC\n");

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
    }

    printf("\nCelsius to Fahrenheit Converter\nC\tF\n");

    for (celsius = UPPER; celsius >= LOWER; celsius -= STEP)
    {
        fahr = celsius * (9.0/5.0) + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
    }

    return 0;
}
