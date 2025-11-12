#include <cs50.h>
#include <math.h>
#include <stdio.h>

int num(long credit_card);
int multiply(int last);
int digit_numbers(long user_credit);
bool American(long user_card, int number_of_digits);
bool Master(long user_card, int number_of_digits);
bool Visa(long user_card, int number_of_digits);

int main(void)
{
    long user_card = get_long("Card number: ");
    int final_num = num(user_card);
    int number_of_digits = digit_numbers(user_card);
    bool american = American(user_card, number_of_digits);
    bool master = Master(user_card, number_of_digits);
    bool visa = Visa(user_card, number_of_digits);
    if (final_num % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (american == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

int digit_numbers(long user_credit)
{
    int count = 0;
    while (user_credit > 0)
    {
        count += 1;
        user_credit /= 10;
    }
    return count;
}

int num(long user_card)
{
    int sum = 0;
    bool alternate = false;
    while (user_card > 0)
    {
        if (alternate == true)
        {
            int last = user_card % 10;
            int product = multiply(last);
            sum += product;
        }
        else
        {
            int last = user_card % 10;
            sum += last;
        }
        alternate = !alternate;
        user_card /= 10;
    }
    return sum;
}

int multiply(int last)
{
    int multiply = last * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_multiply = multiply % 10;
        sum += last_multiply;
        multiply /= 10;
    }
    return sum;
}

bool American(long user_card, int number_of_digits)
{
    int first = user_card / pow(10, 13);
    if ((number_of_digits == 15) && (first == 34 || first == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Visa(long user_card, int number_of_digits)
{
    if (number_of_digits == 13)
    {
        int first = user_card / pow(10, 12);
        if (first == 4)
        {
            return true;
        }
    }
    else if (number_of_digits == 16)
    {
        int first = user_card / pow(10, 15);
        if (first == 4)
        {
            return true;
        }
    }
    return false;
}

bool Master(long user_card, int number_of_digits)
{
    int first = user_card / pow(10, 14);
    if ((number_of_digits == 16) && (first < 56 && first > 50))
    {
        return true;
    }
    else
    {
        return false;
    }
}
