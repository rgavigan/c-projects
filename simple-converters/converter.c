#include <stdio.h>

/*
    Name: Converter
    Purpose: Converts values between different measurement types
    Author: Riley Emma Gavigan, 251150776
*/

int main(void) {
    /* Prompt User and Provide Options */
    int conversionType;
    while (conversionType != 5) {
        while ((conversionType < 1 || conversionType > 4) && conversionType != 5) {
            printf("Enter the type of conversion: \n");
            printf("\t1 -> Convert Between Kilograms and Pounds\n");
            printf("\t2 -> Convert Between Hectares and Acres\n");
            printf("\t3 -> Convert Between Litres and Gallons\n");
            printf("\t4-> Convert Between Kilometres and Miles\n");
            printf("\t5 -> Quit\n");
            scanf("%d", &conversionType);
        }

        /* Prompt User For Conversion Direction */
        char conversionDirection;
        switch (conversionType)
        {
            case 1:
                printf("Enter Conversion Direction:\n");
                printf("\tK: Kilograms -> Pounds\n");
                printf("\tP: Pounds -> Kilograms\n");
                while (!(conversionDirection == 'K' || conversionDirection == 'P')) {
                    while ((conversionDirection = getchar()) == ' ');
                }
                break;
            case 2:
                printf("Enter Conversion Direction:\n");
                printf("\tH: Hectares -> Acres\n");
                printf("\tA: Acres -> Hectares\n");
                while (!(conversionDirection == 'H' || conversionDirection == 'A')) {
                    while ((conversionDirection = getchar()) == ' ');
                }
                break;
            case 3:
                printf("Enter Conversion Direction:\n");
                printf("\tL: Litres -> Gallons\n");
                printf("\tG: Gallons -> Litres\n");
                while (!(conversionDirection == 'L' || conversionDirection == 'G')) {
                    while ((conversionDirection = getchar()) == ' ');
                }
                break;
            case 4:
                printf("Enter Conversion Direction:\n");
                printf("\tK: Kilometres -> Miles\n");
                printf("\tM: Miles -> Kilometres\n");
                while (!(conversionDirection == 'K' || conversionDirection == 'M')) {
                    while ((conversionDirection = getchar()) == ' ');
                }
                break;
            case 5:
                return 0;
                break;
        }

        /* Prompt user for value */
        float inputValue;
        printf("Please enter a value you would like to convert:\n");
        scanf("%f", &inputValue);

        /* Display converted result */
        float convertedValue;
        switch (conversionDirection)
        {
            case 'K':
                // Kilograms to Pounds
                if (conversionType == 1) {
                    convertedValue = inputValue * 2.20462;
                }
                // Kilometres to Miles
                else if (conversionType == 4) {
                    convertedValue = inputValue * 0.621371;
                }
                break;
            case 'P':
                convertedValue = inputValue * 0.453592;
                break;
            case 'H':
                convertedValue = inputValue * 2.47105;
                break;
            case 'A':
                convertedValue = inputValue * 0.404686;
                break;
            case 'L':
                convertedValue = inputValue * 0.264172;
                break;
            case 'G':
                convertedValue = inputValue * 3.78541;
                break;
            case 'M':
                convertedValue = inputValue * 1.60934;
                break;
        }
        printf("Your conversion is: %f\n\n", convertedValue);
        conversionType = 0;
        conversionDirection = 'z';
    }
}