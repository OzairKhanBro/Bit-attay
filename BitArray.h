#ifndef BITARRAY_H
#define BITARRAY_H

#include <iostream>
#include<cmath>
using namespace std;


class BitArray
{
private:
	int capacity;
	unsigned char * data;
	int isValidBit(int i)
	{
		return i >= 0 && i < capacity;
	}
public:
	int getCapacity()
	{
		return capacity;
	}

	BitArray(int n = 8)
	{
		capacity = n;
		int s = (int)ceil((float)capacity / 8);
		data = new unsigned char[s];
		for (int i = 0; i<s; i++)
		{
			data[i] = data[i] & 0;
		}
	}
	BitArray(const BitArray & ref)
	{
		capacity = ref.capacity;
		int s = (int)ceil((float)capacity / 8);
		data = new unsigned char[s];
		memcpy(data, ref.data, capacity);

	}
	void on(int value)
	{
		if (!isValidBit(value))
			throw exception("Invelid Index\n");
		data[value / 8] = data[value / 8] | (1 << (value % 8));
	}
	void off(int value)
	{
		if (!isValidBit(value))
			throw exception("Invelid Index\n");
		data[value / 8] = data[value / 8] & ~(1 << (value % 8));
	}
	bool chech(int value)
	{
		if (!isValidBit(value))
			throw exception("Invelid Index\n");
		return ((data[value / 8] & (1 << (value % 8))) != 0);
	}
	bool operator[](int value)
	{
		if (!isValidBit(value))
			throw exception("Invelid Index\n");
		return ((data[value / 8] & (1 << (value % 8))) != 0);
	}
	void invert(int value)
	{
		if (!isValidBit(value))
			throw exception("Invelid Index\n");
		if ((data[value / 8] & (1 << (value % 8))) == 0)
			on(value);
		else
			off(value);
	}
	void dump()
	{
		unsigned char mask = 1 << (8 - 1);
		int s = (int)ceil((float)capacity / 8);
		int remainder = 8;
		int rem = capacity % 8;
		for (int i = s - 1; i >= 0; i--)
		{
			unsigned char value = data[i];
			if (i == s - 1 && rem != 0)
			{
				remainder = rem;
				mask = 1 << (rem - 1);
			}
			else
			{
				remainder = 8;
				mask = 1 << (8 - 1);
			}
			for (int j = 0; j<remainder; j++)
			{
				cout << ((value & mask) == 0 ? '0' : '1');
				mask = mask >> 1;
			}
			cout << " ";
		}
	}
	BitArray AND(BitArray & ref)
	{
		int resSize = capacity > ref.capacity ?
			ref.capacity : capacity;
		BitArray ba(resSize);
		int bit;
		for (int i = 0; i<resSize; i++)
		{
			bit = chech(i) & ref.chech(i);
			bit ? ba.on(i) : ba.off(i);
		}
		return ba;
	}
	BitArray OR(BitArray & ref)
	{
		int resSize = capacity > ref.capacity ?
			ref.capacity : capacity;
		BitArray ba(resSize);
		int bit;
		for (int i = 0; i<resSize; i++)
		{
			bit = chech(i) | ref.chech(i);
			bit ? ba.on(i) : ba.off(i);
		}
		return ba;
	}

	void shiftLeft(int shiftAmount)
	{
		int start = capacity - shiftAmount - 1;
		int i, j;
		for (i = start, j = capacity - 1; i >= 0; i--, j--)
		{
			chech(i) == 1 ? on(j) : off(j);
		}
		for (i = 0; i<shiftAmount; i++)
		{
			off(i);
		}
	}
	void shiftRight(int bit)
	{
		int j = 0;
		for (int i = bit; i < capacity; i = i + 1, j = j + 1)
		{
			if (chech(i) == 0)
				off(j);
			else
				on(j);
		}

		for (int i = 1; i <= bit; i = i + 1)
			off(capacity - i);
	}
	unsigned long long getUnsignedIntegeralValue()
	{
		unsigned long long int num = 0;
		unsigned long long x = 1;
		for (int i = 0; i<capacity; i++)
		{
			if (chech(i))
				num = num + x;
			x = x * 2;
		}
		return num;
	}
	//void setItegralValue(long long);


	~BitArray()
	{
		if (data)
		{
			delete[] data;
		}
		data = 0;
		capacity = 0;
	}
};

#endif