// Jason Berinsky
// February 13, 2019
// CS 50 Problem Set 2
// Applies a Caesar Cipher to the letters of a string, preserve upper/lower case
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int int_check(string);
int shift(string);

int main(int argc, string argv[])
{
    if (argc == 2 && int_check(argv[1]) == 1)
    {
        string plaintext = get_string("plaintext: ");
        string cipher = plaintext;
        int length = strlen(plaintext);
        int shift_value = shift(argv[1]);
        for (int i = 0; i < length; i++)
        {
            if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
            {
                cipher[i] = 'A' + (((plaintext[i] - 'A') + shift_value) % 26);
            }
            else if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
            {
                cipher[i] = 'a' + (((plaintext[i] - 'a') + shift_value) % 26);
            }
        }     
        printf("ciphertext: %s\n", cipher);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

// Checks if a string is an integer
int int_check(string s)
{
    int isdig;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] > '9' || s[i] < '0')
        {
            isdig = 0;
            break;
        }
        else
        {
            isdig = 1;
        }
    }
    return isdig;
}

// Converts a string of numbers into an integer
int shift(string s)
{
    int mult = 1;
    int value = 0;
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        value += mult * (s[i] - 48);
        mult *= 10;
    }
    return value;
}
