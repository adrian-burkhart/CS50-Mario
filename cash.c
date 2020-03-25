#include <stdio.h>
#include <cs50.h>
#include <math.h>


float change_input;
int main(void)
{    
    do
    {
        change_input = get_float("How much change?"); // Gets a float as input from the user.
    }
    while (change_input < 0);

    int change = round(change_input * 100); // Converts the input into an integer.

    int result;
    int remainder;
    
    result = change / 25; // The amount of quarters.
    remainder = change % 25;
    if (remainder != 0) // If there is still money left.
    {
        result = result + (remainder / 10); // The amount of dimes.
        remainder = remainder % 10;
    }
    if (remainder != 0)
    {
        result = result + (remainder / 5); // The amount of nickels.
        remainder = remainder % 5;
    }
    if (remainder != 0)        
    {
        result = result + (remainder / 1); // The amount of pennies.
    }

    printf("%i\n", result); // Prints the result.
}   
    
