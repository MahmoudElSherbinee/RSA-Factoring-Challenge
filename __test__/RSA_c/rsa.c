#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#define BUFSIZE 256

/**
 * is_prime - Function that checks whether a number is prime.
 * @n: Number to be checked.
 *
 * Return: True if the number is prime,
 *          false otherwise.
 *
 * Description: Primality test used is trial division: given a number, n,
 * check whether it is evenly divisible by any prime number between 2 and √n
 * (i.e. that the division leaves no remainder). If so, then n is composite.
 * Otherwise, it is prime.[1]
 */
bool is_prime(uint64_t n)
{
	uint64_t i;

	if (n == 2 || n == 3)
		return (true);
	else if (n <= 1 || n % 2 == 0 || n % 3 == 0)
		return (false);
	for (i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return (false);
	}
	return (true);
}


/**
 * find_factor - Function that finds the smallest prime factor of a number.
 * @n: Number for which the smallest prime factor is to be found.
 *
 * Return: The smallest prime factor of the number,
 *          or the number itself if it is prime.
 */
uint64_t find_factor(uint64_t n)
{
	uint64_t sqrt_n = sqrt(n);
	uint64_t factor = 2;

	if (n <= 1)
		return (n);
	while (factor <= sqrt_n)
	{
		if (n % factor == 0 && is_prime(factor))
		{
			return (factor);
		}
		factor++;
	}
	return (n);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: 0 on success, non-zero on failure.
 */
int main(int argc, char *argv[])
{
	uint64_t n, p, q;
	FILE *file;
	char buf[BUFSIZE];

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Cannot open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buf, BUFSIZE, file) != NULL)
	{
		n = strtoull(buf, NULL, 10);
		p = find_factor(n);
		q = n / p;
		printf("%llu=%llu*%llu\tL:%d\n", n, p, q, __LINE__);
	}
	fclose(file);
	return (0);
}
