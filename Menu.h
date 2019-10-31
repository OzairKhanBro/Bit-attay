#pragma once
#include"MenuItem.h"
class Menu
{
	MenuItem ** itemList;
	int capacity;
	int noOfItems;
public:
	Menu(int size = 10);
	Menu(const Menu&ref);
	Menu& operator = (const Menu& ref);
	bool isFull()const;
	void reSize(int newSize);
	bool isEmpty();
	bool addItem(const MenuItem & nm);
	bool removeItem(const CString & nm);
	int searchItemPosition(CString nm);
	int getNoOfItems()const;
	void displayMenu()const;
	~Menu();





};