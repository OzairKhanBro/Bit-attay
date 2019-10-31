#include"stdafx.h"
#include"MenuItem.h"
#include<iostream>
using namespace std;
const ostream & operator << (const ostream & os, const MenuItem& item)
{
	item.displayMenuItem();
	return os;
}
const istream & operator >> (const istream & is, MenuItem & item)
{
	item.inputMenuItem();
	return is;
}
MenuItem::MenuItem()
{
	price = 0;
	quantity = 0;
}
MenuItem::MenuItem(CString iN, double pr, int q) :itemName(iN)
{
	price = pr;
	quantity = q;
}
void MenuItem::displayMenuItem() const
{
	cout << "\n\n-----------------------";
	cout << "\n\nitem Name : ";
	itemName.display();
	cout << "\n\nitem Price : " << price ;
	cout << "\n\nitem Quantity : " << quantity << "\n\n";



}

void MenuItem::setItemName(CString nm)
{
	itemName = nm;
}

void MenuItem::setItemPrice(double nm)
{

	price = nm;
}

void MenuItem::setItemQuantity(int nm)
{
	quantity = nm;
}

CString MenuItem::getItemName() const
{
	return itemName;
}

double MenuItem::getPrice() const
{
	return price;
}

int MenuItem::getQuantity() const
{
	return quantity;
}

void MenuItem::inputMenuItem()
{
	int quantity;
	double price;
	CString name;

	cout << "Enter Item Name: ";
	name.input();
	while (name.isEmpty())
	{
		cout << "Item Name Empty is not Allowed: ";
		cout << "Enter Item Name: ";
		name.input();
	}
	cout << "Enter Item Price: ";
	cin >> price;
	while (price <= 0.0)
	{
		cout << "You Entered Invalid Price.";
		cout << "Enter Item Price: ";
		cin >> price;
	}

	cout << "Enter Item Quantity: ";
	cin >> quantity;
	while (quantity <= 0)
	{
		cout << "You Entered Invalid Quantity: ";
		cout << "Enter Item Quantity: ";
		cin >> quantity;
	}

	setItemName(name);
	setItemQuantity(quantity);
	setItemPrice(price);

}
