#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string x); // The function declaration for counting the letters.
int count_words(string x); // The function declaration for counting the words.
int count_sentences(string x); // The function declaration for counting the sentences.
float find_L(int letters, int words); // The function declaration for calculating L.
float find_S(int sentences, int words); // The function declaration for calculating S.
int grading(float L, float S); //The function declaration for calculating the grade.

int main(void)
{
    string input = get_string("Input text: \n"); // Asks the user to input the text that they want to have graded.

    int letters = count_letters(input); // Returns the count of letters.
    int words = count_words(input); // Returns the count of words.
    int sentences = count_sentences(input); // Returns the count of sentences.

    float L = find_L(letters, words); // Returns L.
    float S = find_S(sentences, words); // Returns S.

    int grade = grading(L, S); // Calculates the grade.
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}


int count_letters(string x) // The function definition for counting the letters.
{
    int length = strlen(x);
    int iterator = 0;
    int i;
    for (i = 0; i <= length; ++i)
    {
        int space = isalnum(x[i]);
        if (space == 0)
        {
            continue;
        }
        else
        {
            iterator++;
        }
    }

    return iterator;
}

int count_words(string x) // The function definition for counting the words.
{
    int length = strlen(x);
    int iterator = 1;
    int i;
    for (i = 0; i <= length; ++i)
    {
        int space = isblank(x[i]);
        if (space == 0)
        {
            continue;
        }
        else
        {
            iterator++;
        }
    }
    return iterator;
}

int count_sentences(string x) // The function definition for counting the sentences.
{
    int length = strlen(x);
    int iterator = 0;
    int i;
    for (i = 0; i <= length; ++i)
    {
        if (x[i] == 46)
        {
            iterator++;
        }
        if (x[i] == 33)
        {
            iterator++;
        }
        if (x[i] == 63)
        {
            iterator++;
        }
        else
        {
            continue;
        }
    }
    return iterator;
}

float find_L(int letters, int words) // Calculates the average number of letters per 100 words in the text.
{
    float result = (float) letters / (float) words * 100;
    return result;
}

float find_S(int sentences, int words) // Calculates the average number of sentences per 100 words in the text.
{
    float result = (float) sentences / (float) words * 100;
    return result;
}
int grading(float L, float S) // Calculates the grade.
{
    float result = 0.0588 * L - 0.296 * S - 15.8;
    int rounded = roundf(result);
    return rounded;
}