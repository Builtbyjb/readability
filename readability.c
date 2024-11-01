#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    //stores the number of words in the user input
    int W = count_words(text);

    //stores the number of letters in the user input
    int L = count_letters(text);

    //computes the number of letters per 100 words.
    float lW = (L / (float) W) * 100;

    //stores the number of sentences in the user input
    int S = count_sentences(text);

    // computes the number of sentences per 100 words.
    float sW = (S / (float) W) * 100;

    /* calcuate the Coleman-Liau index : index = (0.0588 * lW) - (0.296 * sW) - 15.8
    where: lW = (number of letters / number of words) * 100;
           sW = (number of sentences / number of words) * 100;
    */
    float index = (0.0588 * lW) - (0.296 * sW) - 15.8;

    //stores the grade level;
    int gradeLevel = (float) round((float) index);

    //returns the grade level as ouput
    if (gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (gradeLevel > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLevel);
    }
}

//A function to calculate the number of letters
int count_letters(string text)
{
    //stores the number of letters
    int l = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            l++;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            l++;
        }
    }
    return l;
}

//A function to calculate the number of words
int count_words(string text)
{
    //stores the number of words
    int w = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            w++;
        }
    }
    return (w + 1);
}

//A function to calculate the number of words.
int count_sentences(string text)
{
    //stores the number of sentences
    int s = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            s++;
        }
    }
    return s;
}