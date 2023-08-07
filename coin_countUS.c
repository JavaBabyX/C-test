#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed,if the chane > 99c == dollar
    int cents = get_cents();
    printf("Change owed: %i\n", cents);

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Change owed: ");
        if (cents > 100){cents %= 100;}
    }
    while (cents < 0 || cents > 99);

    return cents;
}

int calculate_quarters(int cents)
{
    // return quarters
    int quarters;
    quarters = cents / 25;
    return quarters;
    return 0;
}

int calculate_dimes(int cents)
{
    // return dimes
    int dimes;
    //cents %= 25;
    dimes = cents / 10;
    return dimes;
    return 0;
}

int calculate_nickels(int cents)
{
    // return nickels
    int nickels;
    //cents %= 25;
    //cents %= 10;
    nickels = cents / 5;
    return nickels;
    return 0;
}

int calculate_pennies(int cents)
{
    // return pennies
    int pennies;
    //cents %= 25;
    //cents %= 10;
    //cents %= 5;
    pennies = cents;
    return pennies;
    return 0;
}
