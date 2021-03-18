#include <stdio.h>

float celsius2fahr(float);

int main()
{
    float celsius;
    for (celsius = -10.0; celsius<=50.0; celsius = celsius+10.0)
    {
        float fahr = celsius2fahr(celsius);
        printf("%.2f\t%.2f\n", celsius, fahr);
    }
    return 0;
}

float celsius2fahr(float celsius)
{
    return ((9.0/5.0)*celsius)+32;
}