#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dummy_stock();
void add_stock_item();
void insert_stock(struct stock_item item);
void print_stock_list();

int dummy_stock() {
							// Add some dummy stock items
	struct stock_item item1 = {1, "Book", 10, 12.99};
	insert_stock(item1);
	struct stock_item item2 = {2, "Pen", 20, 2.99};
	insert_stock(item2);
	struct stock_item item3 = {3, "Eraser", 15, 1.49};
	insert_stock(item3);
	return 0;
}

							// Function to add a stock item to the global stock list
void add_stock_item() {	
	if (stock_list[MAX_STOCK_ITEMS-1].id != 0) {	// Check if stock list is full
		printf("Stock list is full!\n");
		return;
	}
	else
	{					
		struct stock_item item;
		printf("Enter new item code: ");
		scanf("%d", &item.id);
		printf("Enter new item name: ");
		scanf("%s", item.name);
		printf("Enter new quantity: ");
		scanf("%d", &item.quantity);
		printf("Enter new price: ");
		scanf("%f", &item.price);
		insert_stock(item);
		print_stock_list();
	}
}

void insert_stock(struct stock_item item){
	
					// Add stock item to the first empty slot in the stock list
	for (int i = 0; i < MAX_STOCK_ITEMS; i++) {
		if (stock_list[i].id==item.id) 
		{
			stock_list[i].price=(stock_list[i].price*stock_list[i].quantity+transaction)/(stock_list[i].quantity+item.quantity);
			stock_list[i].quantity+=item.quantity;
			break;
		}
		else if (stock_list[i].id == 0) {
        		stock_list[i] = item;
        		break;
    		}
	}
}