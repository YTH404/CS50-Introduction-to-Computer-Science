// Declare the necessary libraries
#include <cs50.h>
#include <stdio.h>

// Main program
int main()
{
    // Asks the name
    string name = get_string("What's your name? ");

    // Printing "hello, (then name, then enter)"
    printf("hello, %s\n", name);
}
