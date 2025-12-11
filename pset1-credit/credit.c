// Declare the necessary libraries
#include <cs50.h>
#include <stdio.h>

// Declare the header of existing functions
int getLength(long);
void printResult(int, int, int);

// Main program
int main()
{
    // Declare the necessary variables
    bool isSecondToLast = false;
    int firstTwoDigit, sumDigit = 0;

    // Asks for credit number
    long credit = get_long("Number: ");

    // Declare length and use getLength function to get credit number's length
    int length = getLength(credit);

    // Looping for Luhn's algorithm and to get card's first two digit
    // Credit number will be devided by 10 each iteration
    for (; credit > 0; credit = credit / 10)
    {
        // Get the first two digit once credit number reaches tens number
        if ((credit / 10) < 10 && (credit / 10) > 0)
        {
            firstTwoDigit = credit;
        }

        // Get the card's last digit in this itteration
        int currentDigit = credit % 10;

        // Multiply every second-to-last digit by 2
        if (isSecondToLast == true)
        {
            currentDigit = currentDigit * 2;

            // Separate the number if it exceeds 10, then sum both number
            if (currentDigit >= 10)
            {
                currentDigit = (currentDigit / 10) + (currentDigit % 10);
            }
        }

        // Sum the last digit in every itteration
        sumDigit = sumDigit + currentDigit;

        // The changes used to scan if current itteration is managing
        // the second-to-last digit or not
        isSecondToLast = !isSecondToLast;
    }
    // Checking if the sum of the last digits' modulo is 0
    int sumDigitModulo = sumDigit % 10;

    // Calling function printResult to get result
    printResult(sumDigitModulo, length, firstTwoDigit);
}

// Function getLength to count the parameter's length
int getLength(long credit)
{
    // Declare length
    int length = 0;

    // Looping that counts length
    for (; credit > 0; credit = credit / 10)
    {
        length++;
    }

    // Returning length's value
    return length;
}

// Function printResult to divide the results
void printResult(int sumDigitModulo, int length, int firstTwoDigit)
{
    // Check if modulo of sum digit is 0 (used in Luhn's algorithm)
    if (sumDigitModulo == 0)
    {
        // Differentiate card's type based on lenght and its first two digit
        if (length == 15 && (firstTwoDigit == 34 || firstTwoDigit == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 16 && firstTwoDigit >= 51 && firstTwoDigit <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((length == 13 || length == 16) && firstTwoDigit >= 40 && firstTwoDigit <= 49)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
