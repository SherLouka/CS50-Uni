#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calc_score(string Player);
int define_winner(int score1, int score2);

int main(void)
{
    string Player1 = get_string("Player 1: ");
    string Player2 = get_string("Player 2: ");
    int score1 = calc_score(Player1);
    int score2 = calc_score(Player2);
    define_winner(score1, score2);
}

int calc_score(string Player)
{
    int score = 0;
    int len = strlen(Player);
    for (int i = 0; i < len; i++)
    {
        if (isupper(Player[i]))
        {
            score += Points[Player[i] - 'A'];
        }
        else if (islower(Player[i]))
        {
            score += Points[Player[i] - 'a'];
        }
    }
    return score;
}

int define_winner(int score1, int score2)
{
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else
    {
        printf("tie!\n");
    }
    return 0;
}
