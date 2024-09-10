/*
	Cole Swinford
	Lab 3, Sec. 1
	January 26, 2022
	Calculator
*/
#include <stdio.h>

int run = 1;
int menu = 1;


void main()
{
	while (run != 0)
	{
		if (menu == 1)
		{
			// Menu
			printf("\n\nCalculator Menu:");
			printf("\n(1) Addition");
			printf("\n(2) Subtraction");
			printf("\n(3) Multiplication");
			printf("\n(4) Divivison");
			printf("\n(5) Modulus (integers only");
			printf("\n(6) Test if prime (integers only)");
			printf("\n(7) Exit");
			menu = 0;
		}

		// Operation
		printf("\n\nPlease choose an operation: ");
		int Operation;
		scanf("%i", &Operation);

		if (0 < Operation < 8)
		{
			menu = 1;
		}

		// Exit
		if (Operation == 7)
		{
			printf("Good Bye!");
			break;
		}

		// Calculations
		float Calculation;
		char Sign;
		int ModulusPrime;

		// For 1-4
		float FirstNum;
		float SecondNum;
		if (Operation<5)
		{
			// First Number
			printf("Enter the first number: ");
			scanf("%f", &FirstNum);

			// Second Number
			printf("Enter the second number: ");
			scanf("%f", &SecondNum);
		}

		// Prime?
		int TestNum;
		if (Operation == 6)
		{
			// Test
			printf("Enter the number to be tested: ");
			scanf("%i", &TestNum);

			// Result
			int i;
			int prime = 2;
			for (i = 2; i <= TestNum / 2; i++)
			{
				if (TestNum % i == 0)
				{
					//Sign = '%';
					//printf("\nNot Prime: %i %c %i = 0", TestNum, Sign, i);
					prime = 1;
					break;
				}
			}
			if (TestNum <= 1)
			{
				printf("\nYou have enetered an invalid number.");
			}
			else
			{
				if (prime == 1)
				{
					Sign = '%';
					printf("\nNot Prime: %i %c %i = 0", TestNum, Sign, i);
				}
				else
				{
					printf("\nPrime!");
				}
			}
			menu = 1;
		}

		// Addition
		if (Operation == 1)
		{
			Calculation = FirstNum + SecondNum;
			Sign = '+';
			// Result
			printf("\n%f %c %f = %f", FirstNum, Sign, SecondNum, Calculation);
			menu = 1;
		}

		// Subtraction
		if (Operation == 2)
		{
			Calculation = FirstNum - SecondNum;
			Sign = '-';
			// Result
			printf("\n%f %c %f = %f", FirstNum, Sign, SecondNum, Calculation);
			menu = 1;
		}

		// Multiplication
		if (Operation == 3)
		{
			Calculation = FirstNum * SecondNum;
			Sign = 'x';
			// Result
			printf("\n%f %c %f = %f", FirstNum, Sign, SecondNum, Calculation);
			menu = 1;
		}

		// Division
		if (Operation == 4)
		{
			Calculation = FirstNum / SecondNum;
			Sign = '/';
			// Result
			printf("\n%f %c %f = %f", FirstNum, Sign, SecondNum, Calculation);
			menu = 1;
		}

		// Modulus Variables
		int FirstMod;
		int SecondMod;
		// Modulus
		if (Operation == 5)
		{
			// First Number
			printf("Enter the first number: ");
			scanf("%i", &FirstMod);

			// Second Number
			printf("Enter the second number: ");
			scanf("%i", &SecondMod);

			ModulusPrime = FirstMod % SecondMod;
			Sign = '%';
			// Result
			printf("\n%i %c %i = %i", FirstMod, Sign, SecondMod, ModulusPrime);
			menu = 1;
		}
	}
}
