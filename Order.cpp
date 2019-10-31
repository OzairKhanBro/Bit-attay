#include"stdafx.h"
#include<iostream>
using namespace std;
#include "Order.h"

Order::Order(int oId, int size):orderId(oId)
{
	capacity = size;
	noOfItems = 0;
	items = new MenuItem*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		items[i] = 0;
	}
}
Order::Order(const Order & ref):orderId(ref.orderId)
{
	if (ref.items)
	{
		capacity = ref.capacity;
		noOfItems = ref.noOfItems;
		items = new MenuItem*[capacity];
		for (int i = 0; i < noOfItems; i++)
		{
			items[i] = new MenuItem(*(ref.items[i]));
		}
	}
}
Order& Order::operator=(const Order & ref)// : orderId(ref.orderId)
{
	if (this == &ref)
		return *this;
	this->~Order();
	capacity = ref.capacity;
	noOfItems = ref.noOfItems;
	items = new MenuItem*[capacity];
	for (int i = 0; i < noOfItems; i++)
	{
		items[i] = new MenuItem(*(ref.items[i]));
	}
	return *this;
}

bool Order::isFull() const
{
	return noOfItems == capacity ? 1 : 0;
}

int Order::getOrderId()const
{
	return orderId;

}

bool Order::isMenuItemExist(const CString & name) const
{
	int i = 0;
	while (i<noOfItems&&(*items[i]).getItemName().isEqual(name)==0)
	{
		i++;
	}
	if (i == noOfItems)
		return 0;
	return 1;
}

bool Order::addMenuItem(const MenuItem & nm)
{
	if (!isFull())
	{
		items[noOfItems] = new MenuItem(nm);
		noOfItems++;
		return 1;
	}
	else
		return 0;
}

bool Order::removeMenuItem(const CString & nm)
{
	int index = searchItemPosition(nm);
	if (index == -1)
		return 0;
	delete items[index];
	items[index] = new MenuItem(*items[noOfItems]);
	delete items[noOfItems];
	items[noOfItems] = 0;
}

int Order::searchItemPosition(CString nm)
{
	int i = 0; 
	while (i < noOfItems&&items[i]->getItemName().isEqual(nm) == 0)
	{
		i++;
	}
	return i == noOfItems ? -1 : i;
}

bool Order::updateMenuItemQuantity(const CString & nm, int qt)
{
	int index = searchItemPosition(nm);
	if (index == -1)
		return 0;
	items[index]->setItemQuantity(qt);
}

double Order::getTotalBill() const
{
	double bill=0.0;
	for (int i = 0; i < noOfItems; i++)
	{
		bill = bill + (items[i]->getPrice()* items[i]->getQuantity());
	}
	return bill;
}

int Order::getNoOfItems() const
{
	return noOfItems;
}

void Order::displayOrder() const
{
	cout << "\n\n order id : " << orderId;

	for (int i = 0; i < noOfItems; i++)
	{
		
		(*items[i]).displayMenuItem();
	}
}

Order::~Order()
{
	if (!items)
		return;
	for (int i = 0; i < noOfItems; i++)
	{
		delete items[i];
		items[i] = 0;//nullptr;
	}
	delete[] items;
	items = nullptr;
	noOfItems = 0;
	capacity = 0;
}
