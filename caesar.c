#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher_text(string text, int key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Key must be a positive integer.\n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    string text = get_string("plaintext: ");
    cipher_text(text, key);
    return 0;
}

void cipher_text(string text, int key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            char offset = islower(text[i]) ? 'a' : 'A';
            printf("%c", (text[i] - offset + key) % 26 + offset);
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
