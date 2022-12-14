
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculator.c"
#include "taxestimate.c"
#include "header.c"
#include "addstock.c"
#include "printmenu.c"
#include "delete.c"
#include "trade.h"



void print_menu();
void top_menu();
int dummy_stock();
void add_stock_item();
void print_stock_list();
void insert_stock(struct stock_item item);
void deleteStock();
void modifyStock();
void trade();
void tax_estimate(float income, float expenditure);
void remove_stock(int stock_id);
void sell_stock(struct TradeInput trade);
void buy_stock(struct TradeInput trade);
void report();
float getStockPrice(int id);
void PNL_MTM_calculator();

float getStockPrice(int id)
{
	int i=0;
	while(stock_list[i].id!=id && stock_list[i].id!=0) i++;
	if (stock_list[i].id==0) return 0;
	return stock_list[i].price;
}


void modifyStock() {
	int stock_id, i=0;
	printf("\nEnter the stock ID of the stock to modify: ");
	scanf("%d",&stock_id);
	while (stock_list[i].id!=stock_id &&stock_list[i].id!=0)
		i++;
	if (i==MAX_STOCK_ITEMS || stock_list[i].id==0)
	{
		printf("\nStock item not found.\n");
		return;
	}
	printf("Enter new item code: ");
	scanf("%d", &stock_list[i].id);
	printf("Enter new item name: ");
	scanf("%s", stock_list[i].name);
	printf("Enter new quantity: ");
	scanf("%d", &stock_list[i].quantity);
	printf("Enter new price: ");
	scanf("%f", &stock_list[i].price);
	print_stock_list();
}






int main()
{
	char username[20];
	char password[20];
	printf("Enter your username: ");
	scanf("%s", username);

	printf("Enter your password: ");
	scanf("%s", password);

					// Authenticate user

	if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0)
	{
    		printf("Authenticated! Welcome, %s\n", username);
		printf("\n\nAdded three stock items\n\n");
		dummy_stock();		//Add dummy stock items
		top_menu();
	}
	else
	{
    		printf("Invalid username or password. Access denied.\n");
	}

	return 0;
}


