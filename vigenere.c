// Jason Berinsky
// February 14, 2019
// CS 50 Problem Set 2
// Applies a Vigenere Cipher to the letters of a string, preserving upper/lower case
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool letter_check(string);

int main(int argc, string argv[])
{
    if (argc == 2 && letter_check(argv[1]) == true)
    {
        string plaintext = get_string("plaintext: ");
        string cipher = plaintext;
        int textlength = strlen(plaintext);
        int keylength = strlen(argv[1]);
        char letter;
        for (int i = 0, j = 0; i < textlength; i++)
        {
            if (argv[1][j]  >= 'a')
            {
                letter = argv[1][j] - 'a';
            }
            else
            {
                letter = argv[1][j] - 'A';
            }
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                cipher[i] = ('A' + ((plaintext[i] - 'A') + letter) % 26);
                j++;
            }
            else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                cipher[i] = ('a' + ((plaintext[i] - 'a') + letter) % 26);
                j++;
            }
            if (j == keylength)
            {
                j = 0;
            }
        }     
        printf("ciphertext: %s\n", cipher);
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
    return 0;
}

// Checks if a string is a series of letters
bool letter_check(string s)
{
    bool isletter = true;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] < 'A' || s[i] > 'z')
        {
            isletter = false;
            break;
        }
        else if (s[i] > 'Z' && s[i] < 'a')
        {
            isletter = false;
            break;
        }
    }
    return isletter;
}
