#pragma once
#include"Order.h"
class OrderList
{
	static int orderIDGen;
	Order ** orders;
	int noOfOreders;
	int capacity;
public:
	OrderList(int size = 10);
	OrderList(const OrderList & ref);
	void reSize(int newSize);
	bool addOrder(Order& ord );
	bool addOrder(const Order & ref);
	bool removeOrder(int id);
	double getTotalEarnings()const;
	int getNumberOfOrders()const;
	void displayOrder(int id)const;
	double getTotalBillOfOreder(int orderId);
	void displayAllOrders()const;
	int searchOrderPosition(int id)const;
	int getOrderId();
	bool isEmpty();
	bool isFull();
	~OrderList();

};