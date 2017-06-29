#include <stdio.h>

/* convert fahrenheit to celsius using a function */
#define LOWER 0
#define UPPER 300
#define STEP 20

float temp_converter(fahrenheit)
{
    float celsius = (5.0/9.0) * (fahrenheit - 32);
    return celsius;
}

int main()
{
    float fahr, celsius;
    printf("Fahrenheit to Celsius Conversion Table\nF\tC\n");

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        celsius = temp_converter(fahr);
        printf("%3.1f\t%6.1f\n", fahr, celsius);
    }

    return 0;
}
