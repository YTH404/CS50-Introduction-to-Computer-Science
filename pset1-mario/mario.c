// Declare the necessary libraries
#include <cs50.h>
#include <stdio.h>

// Declare the header of functions
void printHash(int j);

// Main program
int main()
{
    // Declare i for pyramid's heigh
    int i;

    // Looping until the height is correctly inputted
    do
    {
        // Asks for pyramid's height
        i = get_int("How tall is the pyramid (1-8) : ");
    }
    while (i < 1 || i > 8);

    // Declare variable j for hash
    int j = 1;

    // Start creating pyramid
    while (i > 0)
    {
        // Variable i is used as a reference for
        // the number of spaces in pyramid
        i--;
        for (int space = i; space > 0; space--)
        {
            printf(" ");
        }

        // Looping to add two hash sections
        for (int loop = 2; loop > 0; loop--)
        {
            printHash(j);
            // Looping to add a space between hash sections
            if (loop % 2 == 0)
            {
                printf("  ");
            }
        }
        printf("\n");

        // Hash increasing after each row
        j++;
    }
}

void printHash(int j)
{
    // Looping to get hash as many as the
    // value of variable j
    for (int m = j; m > 0; m--)
    {
        printf("#");
    }
}
