#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Gets an integer from user input for the height of the pyramid.
    int height;
    int z = 1;
    do
    {
        height = get_int("How high do you want the pyramid to be?");
    }
    while (height < 1 || height > 8);
    
    //Prints the pyramid using loops.
    do
    {
        for (int i = 0; i < height; i++)
        {
            for (int y = 1; y < height; y++)
            {
                printf(" "); //Prints the spaces before the hashes.
            }
            for (int z2 = z; z2 > 0; z2--)
            {
                printf("#"); //Prints the hashes.
            }
            printf("\n");
            z = z + 1;
            height = height - 1;
        }
    } 
    while (height > 0);   
}
