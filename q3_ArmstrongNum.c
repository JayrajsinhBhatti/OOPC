#include <stdio.h>
#include <math.h> // For pow function

int main()
{
    int a, originalNumber;
    printf("Enter a 3-digit number: ");
    scanf("%d", &a);

    // Store the original number for comparison
    originalNumber = a;

    int sum = 0;
    int remainder = 0;

    // Calculate the sum of the cubes of the digits
    while (a != 0)
    {
        remainder = a % 10;               // Extract the last digit
        sum += remainder * remainder * remainder; // Cube the digit and add to sum
        a /= 10;                         // Remove the last digit
    }

    // Check if the number is an Armstrong number
    if (originalNumber == sum)
    {
        printf("Entered number is an Armstrong number.\n");
    }
    else
    {
        printf("Entered number is not an Armstrong number.\n");
    }

    return 0;
}

