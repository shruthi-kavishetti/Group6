
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trade();
void sell_stock(struct TradeInput trade);
void buy_stock(struct TradeInput trade);
void insert_stock(struct stock_item item);
void print_stock_list();



void trade(){				// Declare a variable of type TradeInput
	struct TradeInput trade;
	trade.type='Z';
					// Input values for trade
	while (trade.type!='B' && trade.type!='S' && trade.type!='b' && trade.type!='s')
	{
		printf("\nEnter B for buy or S for sell: ");
		scanf(" %c", &trade.type); 	// Note the space before %c to skip leading whitespace
	}
	printf("Enter stock ID to trade: ");
	scanf("%d", &trade.id);
	if (trade.type=='B' || trade.type=='b')
	{
		printf("Enter the name of the stock item: ");
		scanf("%s",trade.name);
	}
	printf("Enter quantity: ");
	scanf("%d", &trade.quantity);
	printf("Enter trade price per stock item: ");
	scanf("%f", &trade.tradePrice);
	printf("Enter other expenses: ");
	scanf("%f", &trade.otherExpenses);
	if (trade.type=='S' || trade.type=='s') sell_stock(trade);
	else if (trade.type=='B' || trade.type=='b') buy_stock(trade);
}


void sell_stock(struct TradeInput trade){
	int i=0;
	while (stock_list[i].id!=trade.id) i++;
	if (stock_list[i].id!=trade.id)
	{
		printf("Stock not found");
		return;
	}
	else if (stock_list[i].quantity<trade.quantity)
	{
		printf("Not enough stocks\n");
		return;
	}
	transaction=trade.quantity*trade.tradePrice+trade.otherExpenses;
	income+=transaction;
	stock_list[i].price=(stock_list[i].price*stock_list[i].quantity+transaction)/(stock_list[i].quantity-trade.quantity);
	stock_list[i].quantity-=trade.quantity;
	printf("Stocks sold");
	if (stock_list[i].quantity==0) remove_stock(trade.id);
								//Update net income
	print_stock_list();
}


void buy_stock(struct TradeInput trade){
	struct stock_item item;
	item.id=trade.id;
	item.quantity=trade.quantity;
	strcpy(item.name,trade.name);
	item.price=trade.tradePrice;
	transaction=trade.quantity*trade.tradePrice+trade.otherExpenses;
	expenditure+=transaction;							//###Update net income
	insert_stock(item);
	printf("Stocks acquired");
	print_stock_list();
}
