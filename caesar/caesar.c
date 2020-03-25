#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

string calculating(string input, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        bool validkey = true;
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false) //Checks whether the key is a valid digit.
            {
                validkey = false;
            }
        }
        if (validkey)
        {
            int i;
            for (i = 1; i < argc; i++)
            {
                int key = atoi(argv[i]);//Converts the string ot an integer
                if (key != 0)
                {
                    printf("%i: its a digit\n", key);
                    string input = get_string("plaintext: "); // Asks the user to input the message in plaintext
                    string cipher = calculating(input, key);
                    printf("ciphertext: %s\n", cipher);// Output
                    return (0);
                }
                else
                {
                    printf("Usage: ./caesar key is zero\n");
                    return (1);
                }
            }
        }

        else
        {
            printf("Usage: ./caesar key\n");
            return (1);
        }
    }


    else
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
}





// Calculates the ciphertext.
string calculating(string input, int key)
{
    string result[strlen(input)];
    for (int j = 0, n = strlen(input); j < n; j++)
    {
        if (isupper(input[j]) != 0)// If plaintext is uppercase.
        {
            if (input[j] + key > 'Z')// To wrap-around.
            {
                int ascii = input[j] - 65 + key;
                int remainder = ascii % 26 + 65;
                input[j] = remainder;
            }
            else
            {
                input[j] = input[j] + key;
            }
        }
        else if (islower(input[j]) != 0)// If plaintext is lowercase.
        {
            if (input[j] + key > 'z')// To wrap-around.
            {
                int ascii = input[j] - 97 + key;
                int remainder = ascii % 26 + 97;
                input[j] = remainder; 
            }
            else
            {
                input[j] = input[j] + key;
            }
        }
        else
        {
            input[j] = input[j];
        }

    }
    return input;
}
