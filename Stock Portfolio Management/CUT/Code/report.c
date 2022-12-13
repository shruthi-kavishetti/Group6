
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 100

void report();
float getStockPrice(int id);


void report()
{
						//Variable Declarations
	int i=0, n=0, stock_id, stock_close;
	int stockID[MAX_SIZE];
	float stock_movement;
						//Array to store stock movement data
	float stock_data[MAX_SIZE];

						//Opening file in read mode
	FILE *file = fopen("../Data/stock_data.txt", "r");
						//Check if file exists
	if(file == NULL)
	{
    		printf("Error: File does not exist.\n");
    		exit(1);
	}
	while (fscanf(file, "%d %f", &stock_id, &stock_close)!=EOF){
		stock_movement = stock_close - getStockPrice(stock_id);
    		stock_data[i] = stock_movement;	
	}	
						//Closing file
	fclose(file);
						//Printing daily stock movement data
	printf("\nDaily Stock Movement Data:\n");
	printf("Stock ID\tStock Movement\n");
	for(i = 0; i < MAX_SIZE; i++)
	{
    		if (stockID[i]<20) printf("%d\t\t%.2f\n", stockID[i], stock_data[i]);
	}

}

