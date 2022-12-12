#include <stdio.h>

struct stock_item {
	int id;
	char name[100];
	int quantity;
	float price;
};

struct TradeInput {
	int id;
	int quantity;
	char name[100];
	char type; 			// B for buy and S for sell
	float tradePrice;
	float otherExpenses;
};

#define MAX_STOCK_ITEMS 100
float expenditure=0,income=0,transaction=0;

struct stock_item stock_list[MAX_STOCK_ITEMS];		// Global stock item array
