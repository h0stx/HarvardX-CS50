#include <stdio.h>
#include <cs50.h>
#include <math.h>//this library is requirded to use "round(dollars)" fuction in line 15

int main(void)
{
    // asks user for change owed , only accepts positive numbers
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    int coins = 0;

    //conditionals check for every type of coin, subtract that coin from the total change and add 1 to the total number of coins
    while (cents >= 25)
    {
        cents -= 25;
        coins++;

    }

    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    while (cents >= 5)
    {
        cents -= 5;
        coins++;

    }

    while (cents >= 1)
    {
        cents -= 1;
        coins++;

    }
    printf("%i\n", coins);// displays the total number of coins needed to give the change
}
