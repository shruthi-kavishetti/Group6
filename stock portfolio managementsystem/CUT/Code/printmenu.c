
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "report.c"

void print_menu();
void top_menu();
void print_stock_list();
void deleteStock();
void modifyStock();
void trade();
void report();
float getStockPrice(int id);
void PNL_MTM_calculator();
void tax_estimate(float income, float expenditure);


void print_menu() {
	printf("\nWelcome to our program!\n");
  	printf("1. Add a stock\n");
  	printf("2. Display available stocks\n");
  	printf("3. Delete a stock item\n");
	printf("4. Modify a stock item\n");
	printf("5. Trade\n");
	printf("6. P&L and MTM Calculator and Report\n");
	printf("7. Tax estimate\n");
  	printf("10. Quit\n");
}

void top_menu() {
  	int choice=0;
	while (choice!=10)
	{					// Print the menu and get the user's choice
  		print_menu();
	  	scanf("%d", &choice);
						// Handle the user's choice
  		switch (choice) {
    			case 1:			// Add a custom stock item
      				add_stock_item();
	      			break;
    			case 2:			// Print available stock items
      				print_stock_list();		
	      			break;
    			case 3:			// Delete a stock item
				deleteStock();
	      			break;
			case 4:			// Modify a stock item
				modifyStock();
				break;
			case 5:			// Trade a stock item
				trade();
				break;
			case 6:			// P&L and MTM calculator
				PNL_MTM_calculator();
				report();
				break;
			case 7:			// Calculate the tax
				tax_estimate(income,expenditure);
				break;
    			case 10:		// Quit the program			
	      			exit(0);
    			default:
      						// Handle invalid input
      				printf("Invalid choice! Please try again.\n");
	      			break;
  		}
	}
}


					// Function to print the current stock list
void print_stock_list() {
	printf("\nID\tName\t\tQuantity\tPrice\n");
	for (int i = 0; i < MAX_STOCK_ITEMS; i++) {
		if (stock_list[i].id != 0) {
			printf("%d\t%s\t\t%d\t\t%.2f\n", stock_list[i].id, stock_list[i].name, stock_list[i].quantity, stock_list[i].price);
		}
	}
}

