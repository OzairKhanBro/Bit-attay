#pragma once
#include"CString.h"
class MenuItem
{
	CString itemName;
	double price;
	int quantity;
public:
	MenuItem();
	MenuItem(CString iN, double pr, int q);
	void displayMenuItem()const;
	void setItemName(CString nm);
	void setItemPrice(double nm);
	void setItemQuantity(int nm);
	CString getItemName()const;
	double getPrice()const;
	int getQuantity()const;
	void inputMenuItem();

};
const ostream & operator << (const ostream & os, const MenuItem& item);
const istream & operator >> (const istream &, MenuItem &);

