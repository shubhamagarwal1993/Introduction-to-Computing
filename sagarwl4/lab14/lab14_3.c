/*
 * This program is supposed to find the greatest common divisor of
 * two integers using Euclid's algorithm. At least one of the
 * arguments must be non-zero.
 *
 * Euclid's algorithm is as follows:
 * gcd(x, y) = { gcd(y, remainder of (x / y))   , if y != 0
 *               x                              , otherwise }
 */

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y)
{
    return gcd(y, x % y);
}

int main(int argc, const char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Compute the GCD of two numbers x and y\n"
                        "Usage: %s x y\n", argv[0]);
        return EXIT_FAILURE;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int result = gcd(x, y);

    printf("The GCD of %d and %d is %d\n", x, y, result);

    return EXIT_SUCCESS;
}
