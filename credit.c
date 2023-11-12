#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    // assign variables
    long split_number = number;
    int sum1 = 0;
    int sum2 = 0;
    int sum = 0;
    int i;
    for (i = 0; split_number > 0; i++)
    {
        // split the number to single digits
        int digit = split_number % 10;
        split_number = split_number / 10;

        // take every second digit starting from second to last
        if (i % 2 != 0)
        {
            // check if digit * 2 is higher than 9 and if so, split again
            if ((digit * 2) < 10)
            {
                digit = digit * 2;
            }
            else
            {
                digit = digit * 2;
                digit = ((digit % 10) + ((digit / 10) % 10));
            }

            // sum all
            sum1 += digit;
        }
        else
        {
            sum2 += digit;
        }
    }
    // sum all numbers and check the last digit from the sum
    sum = sum1 + sum2;
    int endval = sum % 10;

    // check if VISA, AMEX, MASTERCARD OR INVALID
    int firstdigit = number / (long) pow(10, i - 1);
    int twodigits = number / (long) pow(10, i - 2);

    if (endval == 0 && i == 15 && (twodigits == 34 || twodigits == 37))
    {
        printf("AMEX\n");
    }
    else if (endval == 0 && i == 16 &&
             (twodigits == 51 || twodigits == 52 || twodigits == 53 || twodigits == 54 || twodigits == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (endval == 0 && (i == 16 || i == 13) && firstdigit == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
