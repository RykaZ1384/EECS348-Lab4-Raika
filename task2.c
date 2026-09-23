#include <stdio.h> // access to printf() and scanf()
#include <ctype.h> // access to toupper()

int main() { // main function where the program starts

    double temperature; // store the temperature entered
    double celsius; // store temperature in Celsius
    double converted; // store the converted temperature
    char originalScale; // store the original scale
    char targetScale; // store the scale to convert to

    printf("Enter the temperature value: "); // ask for temperature

    // check if the temperature is a valid number
    if (scanf("%lf", &temperature) != 1) {
        printf("Invalid temperature input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): "); // ask for original scale
    scanf(" %c", &originalScale);

    printf("Enter the scale to convert to (C, F, or K): "); // ask for target scale
    scanf(" %c", &targetScale);

    // change lowercase letters to uppercase
    originalScale = toupper(originalScale);
    targetScale = toupper(targetScale);

    // convert the original temperature to Celsius first
    if (originalScale == 'C') {
        celsius = temperature;
    }
    else if (originalScale == 'F') {
        celsius = (temperature - 32) * 5.0 / 9.0;
    }
    else if (originalScale == 'K') {

        // Kelvin cannot be below 0
        if (temperature < 0) {
            printf("Invalid Kelvin temperature.\n");
            return 1;
        }

        celsius = temperature - 273.15;
    }
    else {
        printf("Invalid original scale.\n");
        return 1;
    }

    // convert Celsius to the target scale
    if (targetScale == 'C') {
        converted = celsius;
    }
    else if (targetScale == 'F') {
        converted = (celsius * 9.0 / 5.0) + 32;
    }
    else if (targetScale == 'K') {
        converted = celsius + 273.15;
    }
    else {
        printf("Invalid target scale.\n");
        return 1;
    }

    // show the converted temperature
    printf("Converted temperature: %.2f %c\n", converted, targetScale);

    // find the temperature category using Celsius
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Wear warm clothes!\n");
    }
    else if (celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket!\n");
    }
    else if (celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors!\n");
    }

    return 0; // end program
}
