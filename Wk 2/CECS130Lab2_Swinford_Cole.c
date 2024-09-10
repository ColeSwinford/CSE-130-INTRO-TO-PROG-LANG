/*
	Cole Swinford
	Lab 2, Sec. 1
	January 20, 2022
	Currency Conversion
*/

#include <stdio.h>


main()
{
	// print instructions
	printf("Enter currency amount: ");

	// define conversion factors from USD (USD2X)
	const float USD2GBP = 0.73;
	const float USD2CAD = 1.25;
	const float USD2EUR = 0.88;
	const float USD2AUD = 1.38;
	
	// define conversion factors from GBP (GBP2X)
	const float GBP2USD = 1.36;
	const float GBP2CAD = 1.70;
	const float GBP2EUR = 1.70;
	const float GBP2AUD = 1.88;
	
	// define conversion factors from CAD (CAD2X)
	const float CAD2USD = 0.80;
	const float CAD2GBP = 0.59;
	const float CAD2EUR = 0.71;
	const float CAD2AUD = 1.11;
	
	// define conversion factors from EUR (EUR2X)
	const float EUR2USD = 1.13;
	const float EUR2GBP = 0.83;
	const float EUR2CAD = 1.41;
	const float EUR2AUD = 1.56;
	
	// define conversion factors from AUD (AUD2X)
	const float AUD2USD = 0.72;
	const float AUD2GBP = 0.53;
	const float AUD2CAD = 0.90;
	const float AUD2EUR = 0.64;
	
	// define input variable
	float currency = 0.0;
	
	// take inputs
	scanf("%f",&currency);
	
	// printing results for USD
	printf("\t| USD |\t| GBP |\t| CAD |\t| EUR |\t| AUD |");
	printf("\n|USD|\t|% .2f", currency);
	printf("\t|% .2f", currency*USD2GBP);
	printf("\t|% .2f", currency*USD2CAD);
	printf("\t|% .2f", currency*USD2EUR);
	printf("\t|% .2f", currency*USD2AUD);
	
	// printing results for GBP
	printf("\n|GBP|");
	printf("\t|% .2f", currency*GBP2USD);
	printf("\t|% .2f", currency);
	printf("\t|% .2f", currency*GBP2CAD);
	printf("\t|% .2f", currency*GBP2EUR);
	printf("\t|% .2f", currency*GBP2AUD);

	// printing results for CAD
	printf("\n|CAD|");
	printf("\t|% .2f", currency*CAD2USD);
	printf("\t|% .2f", currency*CAD2GBP);
	printf("\t|% .2f", currency);
	printf("\t|% .2f", currency*CAD2EUR);
	printf("\t|% .2f", currency*CAD2AUD);

	// printing results for EUR
	printf("\n|EUR|");
	printf("\t|% .2f", currency*EUR2USD);
	printf("\t|% .2f", currency*EUR2GBP);
	printf("\t|% .2f", currency*EUR2CAD);
	printf("\t|% .2f", currency);
	printf("\t|% .2f", currency*EUR2AUD);

	// printing results for AUD
	printf("\n|AUD|");
	printf("\t|% .2f", currency*AUD2USD);
	printf("\t|% .2f", currency*AUD2GBP);
	printf("\t|% .2f", currency*AUD2CAD);
	printf("\t|% .2f", currency*AUD2EUR);
	printf("\t|% .2f", currency);
}
