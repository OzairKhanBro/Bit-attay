
#include <iostream>
#include<cmath>
#include <fstream>
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
	void on(int value)
	{
		data[value / 8] = data[value / 8] | (1 << (value % 8));
	}
	bool operator[](int value)
	{
		return ((data[value / 8] & (1 << (value % 8))) != 0);
	}
};

bool path(BitArray& set, int& count, int y, int row, int& max)
{
	if (count > max)
		max = count;
	if (count == row)
		return 1;
	bool tem = false;
	while (count <= row && set[(count + 1) * 3 + 1] != 1)
	{
		count++;
		y = 1;
	}
	while (count <= row && y != 2 && set[(count + 1) * 3 + 1] == 1 && set[(count + 1) * 3 + 0] != 1)
	{
		count++;
		y = 0;
	}
	if (count > max)
		max = count;

	if (count <= row && y != 2 && set[(count + 1) * 3 + 0] != 1)
	{
		count++;
		if (path(set, count, 1, row, max)) return 1;
		count--;
	}
	while (count <= row && y != 0 && set[(count + 1) * 3 + 1] == 1 && set[(count + 1) * 3 + 2] != 1)
	{
		count++;
		y = 2;
	}
	if (count <= row && y != 0 && set[count + 1, 3] != 1)
	{
		count++;
		if (path(set, count, 3, row, max)) return 1;
		count--;
	}
	if (count > max)
		max = count;

	return false;
}
int main()
{
	fstream ifs;
	ifs.open("inp.txt");
	int tcase, row, obs;
	ifs >> tcase;
	for (int j = 0; j < tcase; j++)
	{
		ifs >> row >> obs;
		int x, y;
		BitArray set(row * 3 + 7);
		for (int i = 0; i < obs; i++)
		{
			ifs >> x >> y;
			x--;y--;
			set.on(x * 3 + y);
		}
		int count = 0, max = 0;
		path(set, count, 1, row, max);
		cout << (max + 1>row ? row : max + 1) << "\n";
	}
	return 0;
}
