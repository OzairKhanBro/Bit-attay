#include"Menu.h"
#include<iostream>
using namespace std;
#include"stdafx.h"

Menu::Menu(int size)
{
	capacity = size;
	noOfItems = 0;
	itemList = new MenuItem*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		itemList[i] = 0;
	}
}

Menu::Menu(const Menu & ref)
{

	if (ref.itemList)
	{
		capacity = ref.capacity;
		noOfItems = ref.noOfItems;
		itemList = new MenuItem*[capacity];
		for (int i = 0; i < noOfItems; i++)
		{
			itemList[i] = new MenuItem(*(ref.itemList[i]));
		}
	}
}

Menu & Menu::operator=(const Menu & ref)
{
	if (this == &ref)
		return *this;
	this->~Menu();
	capacity = ref.capacity;
	noOfItems = ref.noOfItems;
	itemList = new MenuItem*[capacity];
	for (int i = 0; i < noOfItems; i++)
	{
		itemList[i] = new MenuItem(*ref.itemList[i]);
	}
	return *this;

	// TODO: insert return statement here
}

bool Menu::isFull() const
{
	return noOfItems == capacity ? 1 : 0;
}

void Menu::reSize(int newSize)
{
	if (newSize <= 0)
	{
		this->~Menu();
		return;
	}
	else
	{
		int tempNo = newSize<noOfItems ? newSize : noOfItems;
		MenuItem ** temp = new MenuItem*[newSize];
		//
		for (int i = 0; i < tempNo&&i<capacity; i++)
		{
			temp[i] = new MenuItem(*itemList[i]);
		}
		this->~Menu();
		itemList = temp;
		capacity = newSize;
		noOfItems = tempNo;
	}


}

bool Menu::isEmpty()
{
	return noOfItems == 0;
}

bool Menu::addItem(const MenuItem & nm)
{

	if (!isFull())
	{
		itemList[noOfItems] = new MenuItem(nm);
		noOfItems++;
		return 1;
	}
	else
		return 0;
}

bool Menu::removeItem(const CString & nm)
{
	int index = searchItemPosition(nm);
	if (index == -1)
		return 0;
	delete itemList[index];
	itemList[index] = new MenuItem(*itemList[noOfItems]);
	delete itemList[noOfItems];
	itemList[noOfItems] = 0;
}

int Menu::searchItemPosition(CString nm)
{
	int i = 0;
	while (i < noOfItems&&itemList[i]->getItemName().isEqual(nm) == 0)
	{
		i++;
	}
	return i == noOfItems ? -1 : i;
}


int Menu::getNoOfItems() const
{
	return noOfItems;
}

void Menu::displayMenu() const
{
	
	for (int i = 0; i < noOfItems; i++)
	{

		(*itemList[i]).displayMenuItem();
	}
}

Menu::~Menu()
{
	if (!itemList)
		return;
	for (int i = 0; i < noOfItems; i++)
	{
		delete itemList[i];
		itemList[i] = 0;//nullptr;
	}
	delete[] itemList;
	itemList = nullptr;
	noOfItems = 0;
	capacity = 0;
}
