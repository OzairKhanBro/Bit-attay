#pragma once
#include"MenuItem.h"

class Order
{
	const int orderId;
	MenuItem ** items;
	int capacity;
	int noOfItems;
public:
	Order(int oId, int size = 10);
	Order(const Order&ref);
	Order& operator = (const Order& ref);
	bool isFull()const;
	int getOrderId()const;

	bool isMenuItemExist(const CString & name)const;
	bool addMenuItem(const MenuItem & nm);
	bool removeMenuItem(const CString & nm);
	int searchItemPosition(CString nm);
	bool updateMenuItemQuantity(const CString & nm, int qt);
	double getTotalBill()const;
	int getNoOfItems()const;
	void displayOrder()const;
	~Order();

};