/*
10) tax estimate report based on tax rules of current FY
*/



#include <stdio.h>

void tax_estimate(float income, float expenditure){
	float tax=0, profit=income-expenditure;
	if (profit <= 50000)
    		tax = 0;
	else if (profit <= 75000)
		tax = (profit - 50000) * 0.1;
	else if (profit <= 100000)
		tax = (profit - 75000) * 0.2 + 2500;
	else if (profit <= 250000)
    		tax = (profit - 100000) * 0.3 + 7500;
	else if (profit <= 500000)
    		tax = (profit - 250000) * 0.4 + 27500;
	else
    		tax = (profit - 500000) * 0.5 + 62500;

	printf("Your estimated tax amount is: %.2f", tax);
}
