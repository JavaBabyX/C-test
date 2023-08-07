#include <stdio.h>

int main(void) {
    for (int i = 0; i<3 ; i++){
        printf("this is\n");
        //this makes 3 (vert) in c
        for (int j=0 ; j<4 ;j++){
          printf("th1s 1s");
          //for each in i, make j zero, while j value under 4, iter j(j+=1 or j++, j= j+1) same genearal formula for the pyramid
          //most likely j+-    ??? seems to call neg int, irr exp
          //for (int j = 0; j<i; j++) , works for r /_ pyramid but still missing logic to make it perfect , an if statement most likely or additional math/operator
          //get_ user input request , int, str?,bool float, double...
    }
    printf("\n"); 
}

/*
%d or %i: Used for printing or reading integers in decimal format. i gives more flexibility
%f: Used for printing or reading floating-point numbers.
%c: Used for printing or reading single characters.
%s: Used for printing or reading strings.
%p: Used for printing or reading pointers.
%x or %X: Used for printing or reading integers in hexadecimal format.
%o: Used for printing or reading integers in octal format.
%u: Used for printing or reading unsigned integers.
%e or %E: Used for printing or reading floating-point numbers in scientific notation.
%g or %G: Used for printing or reading floating-point numbers in either decimal or scientific notation, depending on the value.
%a or %A: Used for printing or reading floating-point numbers in hexadecimal format.
%n: Used for storing the number of characters written so far in a variable.
%lld, %llu, %Lf, etc.: Used for printing or reading long long integers, unsigned long long integers, long double, etc., respectively.
%hu: Used for printing or reading unsigned short integers.
%hi: Used for printing or reading signed short integers.
%o: Used for printing or reading integers in octal format.

// Division with longs, demonstrating floating-point imprecision

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for x
    long x = get_long("x: ");

    // Prompt user for y
    long y = get_long("y: ");

    // Divide x by y
    float z = (float) x / (float) y;
    printf("%.20f\n", z);
}
*/

/*
bool, a Boolean expression of either true or false
char, a single character like a or 2
double, a floating-point value with more digits than a float
float, a floating-point value, or real number with a decimal value
int, integers up to a certain size, or number of bits
long, integers with more bits, so they can count higher than an int
string, a string of characters
*/

/*
#include <cs50.h>
#include <stdio.h>

int get_size(void);
void print_grid(int n);

int main(void)
{
    int n = get_size();
    print_grid(n);
}

int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_grid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
*/
