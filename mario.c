#include <cs50.h>
#include <stdio.h>
void hash(void);
int height, i, column, space;

int main(void)
{
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    for (i = 0; i < height; i++)
    {
        for (space = 0; space < height - i - 1; space++)
        {
            printf(" ");
        }
        hash();
        printf("  ");
        hash();
        printf("\n");
    }
}
void hash(void)
{
    for (column = 0; column <= i; column++)
    {
        printf("#");
    }
}
