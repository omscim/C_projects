#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string convert_to_lowercase(string input);
string convert_to_uppercase(string input);

int main(int argc, string argv[])
{
    // error handling
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string key = argv[1];
    convert_to_lowercase(key);

    // case: incorrect lenght of the string provided
    int n = strlen(key);
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        // case: some characters are non-alphabetical
        if (!(isalpha(key[i])))
        {
            printf("All characters have to be alphabetical.\n");
            return 1;
        }
        // case: some characters are used more than once
        for (int j = 0; j < n; j++)
        {
            if (key[i] == key[j] && j != i)
            {
                printf("Each character can be used only once.\n");
                return 1;
            }
        }
    }

    // create the cypher
    string plaintext = get_string("plaintext: ");
    for (int i = 0, m = strlen(plaintext); i < m; i++)
    {
        int X;
        if (isupper(plaintext[i]))
        {
            convert_to_uppercase(key);
            X = plaintext[i] - 65;
            plaintext[i] = key[X];
        }
        else if (islower(plaintext[i]))
        {
            convert_to_lowercase(key);
            X = plaintext[i] - 97;
            plaintext[i] = key[X];
        }
        else
        {
            plaintext[i] = plaintext[i];
        }
    }

    printf("ciphertext: %s\n", plaintext);
}

string convert_to_lowercase(string input)
{
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        input[i] = tolower(input[i]);
    }
    return input;
}

string convert_to_uppercase(string input)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        input[i] = toupper(input[i]);
    }
    return input;
}
