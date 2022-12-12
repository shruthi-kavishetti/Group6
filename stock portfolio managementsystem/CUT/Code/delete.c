
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteStock();
void remove_stock(int stock_id);
void print_stock_list();



void deleteStock() {
	int stock_id;
	printf("Enter the stock ID of the stock to be deleted: ");
	scanf("%d",&stock_id);
	remove_stock(stock_id);
}


void remove_stock(int stock_id)
	{
	int i=0;
	while (stock_list[i].id!=stock_id) 
		i++;
	while (stock_list[i].id!=0 && i<MAX_STOCK_ITEMS-1)
	{
		stock_list[i]=stock_list[i+1];
		i++;
	}
	if (i==MAX_STOCK_ITEMS-1)
	{
		if (stock_list[i].id!=0)
		{
			stock_list[i].id= 0;
			stock_list[i].name[0] = '\0';
			stock_list[i].quantity = 0;
			stock_list[i].price = 0.0;
		}
	}
	print_stock_list();
}