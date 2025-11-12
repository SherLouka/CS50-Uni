#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid(string key);
void cipher(string text, string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (!is_valid(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }
    else
    {
        string text = get_string("plaintext: ");
        cipher(text, key);
    }
}

bool is_valid(string key)
{
    if (strlen(key) != 26)
    {
        return false;
    }
    bool used[26] = {0}; //This line initializes a boolean array used with 26 elements, all set to false. Each element in this array corresponds to a letter in the alphabet. This array will help track whether each letter has already been used in the key.
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A'; //creates a key to make a = 1 and b = 2 etc.

        if (used[index])
        {
            return false;
        }
        used[index] = true;
    }
    return true;
}

void cipher(string text, string key)
{
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            int index = toupper(text[i]) - 'A';
            if (isupper(text[i]))
            {
                printf("%c", toupper(key[index]));
            }
            else
            {
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
