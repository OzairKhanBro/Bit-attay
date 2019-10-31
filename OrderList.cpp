#include"stdafx.h"
#include"OrderList.h"

int OrderList::orderIDGen = 1;

OrderList::OrderList(int size)
{
	capacity = size;
	noOfOreders = 0;
	orders = new Order*[capacity];
}

OrderList::OrderList(const OrderList & ref)
{
	if (ref.orders)
	{
		capacity = ref.capacity;
		noOfOreders = ref.noOfOreders;
		orders = new Order*[capacity];
		for (int i = 0; i < noOfOreders; i++)
		{
			orders[i] = new Order(*(ref.orders[i]));
		}
	}
}

void OrderList::reSize(int newSize)
{
	if (newSize <= 0)
	{
		this->~OrderList();
		return;
	}
	else
	{
		int tempNo=newSize<noOfOreders?newSize:noOfOreders;
		Order ** temp = new Order*[newSize];
		//
		for (int i = 0; i < tempNo&&i<capacity; i++)
		{
			temp[i] = new Order(*orders[i]);
		}
		this->~OrderList();
		orders = temp;
		capacity = newSize;
		noOfOreders = tempNo;
	}


}

bool OrderList::addOrder(Order & ord)
{
	if (!isFull())
	{
		orders[noOfOreders] =new Order(ord);
		noOfOreders++;

	}
	else
	{
		return 0;
	}

}

bool OrderList::removeOrder(int id)
{
	int pos = searchOrderPosition(id);
	if (pos == -1)
		return false;
	orders[pos]->~Order();
	orders[pos] = new Order(*orders[noOfOreders]);
	orders[noOfOreders]->~Order();
	noOfOreders--;
	return 1;

}

double OrderList::getTotalEarnings() const
{
	double earnings=0.0;
	for (int i = 0; i < noOfOreders; i++)
	{
		earnings += orders[i]->getTotalBill();
	}
	return earnings;
}

int OrderList::getNumberOfOrders() const
{
	return noOfOreders;
}

void OrderList::displayOrder(int id) const
{
	int index = searchOrderPosition(id);
	if (index != -1)
	{
		orders[index]->displayOrder();
	}
}

double OrderList::getTotalBillOfOreder(int orderId)
{
	int index = searchOrderPosition(orderId);
	if (index != -1)
	{
		return orders[index]->getTotalBill();
	}
}

void OrderList::displayAllOrders() const
{
	for (int i = 0; i < noOfOreders; i++)
	{
		orders[i]->displayOrder();
	}
}

int OrderList::searchOrderPosition(int id) const
{
	int i = 0; 
	while (i < noOfOreders&&orders[i]->getOrderId() != id)
	{
		i++;
	}
	return i == noOfOreders ? -1 : i;

}

int OrderList::getOrderId()
{
	return orderIDGen;
	orderIDGen++;
}

bool OrderList::isEmpty()
{
	return noOfOreders == 0 ? 1 : 0;
}

bool OrderList::isFull()
{
	return noOfOreders == capacity ? 1 : 0;
}

OrderList::~OrderList()
{
	if (orders)
	{
		for (int i = 0; i < noOfOreders; i++)
		{
			delete orders[i];
			orders[i] = 0;
		}
		delete[] orders;
		orders = nullptr;
		capacity = 0;
		noOfOreders = 0;
	}
}

