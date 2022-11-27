#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void printElements(int arr[], int length) {
    /*
    Prints out elements of the array and their position
    */
    printf("Part 1: \n");
    printf("    Your array is: ");
    for (int i = 0; i < length; i++) {
        // Final element
        if (i == length - 1) {
            printf("[%d] = %d\n\n", i, arr[i]);
        }
        // All other elements
        else {
            printf("[%d] = %d,  ", i, arr[i]);
        }
    }
}

void largestValue(int arr[], int length) {
    /*
    Gets largest value in array and prints it out
    */

    // Get largest
    int largest = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Print largest
    printf("Part 2:\n");
    printf("    The largest value in your array is: %d\n\n", largest);
}

void printReverse(int arr[], int length) {
    /*
    Prints out elements of array in reverse order
    */
    printf("Part 3: \n");
    printf("    Your array in reverse is: ");
    for (int i = (length - 1); i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void sumArray(int arr[], int length) {
    /*
    Prints out the sum of all array values
    */

    // Get sum
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    
    // Print sum
    printf("Part 4: \n");
    printf("    The sum of all values in your array is: %d\n", sum);
    printf("\n");
}

void swap(int* x, int*y) {
    /*
    Helper function for Selection Sort and Swapping
    */

    int temp = *x;
    *x = *y;
    *y = temp;
}

void descendingOrder(int arr[], int length) {
    /*
    Prints out elements of array in descending order
    */

    // Copy arr
    int sorted[length];
    for (int i = 0; i < length; i++) {
        sorted[i] = arr[i];
    }


    // Selection Sort
    int min_index;
    for (int i = 0; i < length - 1; i++) {
        min_index = i;
        for (int j = i + 1; j < length; j++) {
            if (sorted[j] > sorted[min_index]) {
                min_index = j;
            }
        }
        swap(&sorted[min_index], &sorted[i]);
    }

    // Print sorted array
    printf("Part 5: \n");
    printf("    Your array in sorted order is: ");
    for (int l = 0; l < length; l++) {
        printf("%d ", sorted[l]);
    }
    printf("\n\n");
}

void swapFirstLast(int arr[], int length) {
    /*
    Prints out elements of array after swapping first and last element
    */

    // Copy arr
    int swapped[length];
    for (int i = 0; i < length; i++) {
        swapped[i] = arr[i];
    }

    // Swap first and last
    int first = 0;
    int last = length - 1;
    swap(&swapped[first], &swapped[last]);

    // Print out swapped array
    printf("Part 6: \n");
    printf("    Your array with first and last element switched is: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", swapped[i]);
    }
    printf("\n\n");
}

int main(void) {
    /*
    Program takes integers and creates an array, which then
    displays different results from this array
    */

    // Get length
    int length;
    // Make sure between 5-12 integers are provided
    while (length < 5 || length > 12) {
        printf("Please enter the number of integers to process: ");
        scanf("%d", &length);
    }

    // Create array
    int arr[length];
    int bytes = sizeof(arr);
    printf("    There is enough room for in your array for %d integers (%d bytes)\n\n", length, bytes);

    // Initialize array to hold numbers and spaces, split array, and i/j values
    char charArr[100];
    char *split;
    int i, isChar, count;
    while (1) {
        i = 0, isChar = 0, count = 0;
        // Read input to charArr
        printf("Please enter your integers separated by spaces: \n");
        fflush(stdin);
        fgets(charArr, 100, stdin);

        // Split up array by spaces
        split = strtok(charArr, " ");
        while (split) {
            // Convert to int
            int num = atoi(split);
            
            // Handle chars
            if (num == 0) {
                isChar = 1;
            }
            // Add num to arr[i] and then increment everything
            arr[i] = num;
            split = strtok(NULL, " ");
            i++;
            count++;
        }
        // Break loop only if all valid integers were added and the count is correct
        if (isChar == 0 && count == length) {
            break;
        }
    }
    printf("%c", *arr);

    // Call functions on array
    printElements(arr, length);
    largestValue(arr, length);
    printReverse(arr, length);
    sumArray(arr, length);
    descendingOrder(arr, length);
    swapFirstLast(arr, length);
}