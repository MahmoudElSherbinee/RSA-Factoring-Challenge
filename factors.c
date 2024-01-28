#include <stdio.h>

/**
  * main - Factorize some numbers and print result
  *
  * Return: Always success
  */

int main(void)
{
	long long int num;
	long int factor1 = 2;
	long int factor2;

	printf("Please enter some numbers: ");
	scanf("%lli", &num);

	while (num % factor1)
	{
		if (factor1 <= num)
		{
			factor1++;
		}
		else
		{
			return (-1);
		}
	}

	factor2 = num / factor1;
	printf("%lld = %ld * %ld\n", num, factor2, factor1);

	return (0);
}
