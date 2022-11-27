#include <stdio.h>

/*
    Name: Integer to English
    Purpose: Convert an integer in the range 1-999 into its English representation
    Author: Riley Emma Gavigan, 251150776
*/

int main(void) {
    // Array: Holds English representation for 1-19 by index i.e. (numMap[2] = two)
    char* numMap[] = {
        "", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve",
        "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };

    // Array: Holds English representation for tens by index i.e. (tensMap[4] = fourty)
    char* tensMap[] = {
        "", "", "twenty", "thirty", "fourty", "fifty", "sixty",
        "seventy", "eighty", "ninety"
    };

    // Prompt user to enter a number
    int input;
    while (input != 0) {
        printf("Please enter a value (1-999, 0 to quit): \n");
        scanf("%d", &input);
        if (input == 0) {
            return 0;
        }

        // Range: 1-9
        if (input < 10) {
            printf("You entered the number %s\n", numMap[input]);
        }
        // Range: 10-99
        else if (input < 100) {
            printf("You entered the number ");
            // Range: 10-19
            if (input < 20) {
                printf("%s\n", numMap[input]);
            }
            // Range: 20-99
            else {
                int ones, tens;
                ones = input % 10;
                tens = input / 10;
                printf("%s %s\n", tensMap[tens], numMap[ones]);
            }
        }
        // Range: 100-999
        else if (input < 1000) {
            int ones, lastTwo, hundreds;
            ones = input % 10;
            lastTwo = input % 100;
            hundreds = input / 100;
            printf("You entered the number ");
            printf("%s hundred ", numMap[hundreds]);
            if (lastTwo < 20) {
                printf("%s\n", numMap[lastTwo]);
            }
            // Handle 20-99
            else {
                int first, second;
                second = lastTwo % 10;
                first = lastTwo / 10;
                printf("%s %s\n", tensMap[first], numMap[second]);
            }
        }
    }
}