/*
9)P&L and MTM calculator and report  displayed on selecting a menu
*/


#include <stdio.h>



#define MAX_SIZE 100
float getStockPrice(int id);


void PNL_MTM_calculator()
{
	int menuCode;
	float PNL, MTM;
	printf("Enter the menu code: ");
	scanf("%d", &menuCode);

					// Calculate P&L and MTM based on the menu code
	switch(menuCode)
	{
	    	case 1:
        		PNL = 100;
        		MTM = 50;
        		break;
	    	case 2:
        		PNL = 200;
        		MTM = 120;
	        	break;
		case 3:
        		PNL = 300;
	        	MTM = 180;
        		break;
	    	case 4:
        		PNL = 400;
        		MTM = 240;
	        	break;
	    	default:
        		printf("Invalid menu code!");
        		return;
	}				// Display P&L and MTM report
	printf("P&L: %.2f\n", PNL);
	printf("MTM: %.2f\n", MTM);
}

