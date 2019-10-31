#include"stdafx.h"
#include"CString.h"
#include<iostream>
using namespace std;



CString CString::concat(const CString& s2) const
{

	int l = getLenght();
	int l1 = s2.getLenght();
	CString ch;
	int i = 0;

	for (int i = 0; i < l; i++)
	{
		if (i >= ch.size - 1)
		{
			ch.at(i) = '\0';
			ch.resize(size * 2);
		}

		ch.data[i] = data[i];
	}
	for (int i = 0; i < l1; i++)
	{
		if (l >= ch.size - 1)
		{
			ch.at(i) = '\0';
			ch.resize(size * 2);
		}
		ch.data[l] = s2.data[i];
		l++;
	}
	ch.data[l] = '\0';
	return ch;


}
CString CString::right(int count)
{
	int i = 0;
	int position = 0;
	CString ch1;
	while (i < count)
	{
		if (i >= ch1.size - 1)
		{
			ch1.at(i) = '\0';
			resize(size * 2);
		}
		ch1.data[i] = data[position];
		position++;
		i++;
	}
	ch1.data[i] = '\0';
	return ch1;

}
CString CString::left(int count)
{
	if (count == getLenght())
	{

		return *this;
	}
	int l = getLenght();
	l = l - 1;
	int i = 0;
	int position = l - count;
	CString ch1;
	while (i < count)
	{
		if (i >= ch1.size - 1)
		{
			ch1.at(i) = '\0';
			resize(size * 2);
		}
		ch1.data[i] = data[position + 1];
		position++;
		i++;
	}
	ch1.data[i] = '\0';
	return ch1;
}
bool CString::isPresentInDelim(const char*delim, char ch)
{
	int i = 0;
	while (delim[i] != '\0')
	{
		if (ch == delim[i])
		{
			break;
		}
		i++;
	}
	if (delim[i] == '\0')
	{
		return false;
	}
	else
		return true;
}
CString CString::tokenzier(const char * const delim)
{
	CString token;

	int i = 0;

	if (delim[0] == '\0')
	{
		token = *this;
		data[0] = '\0';
		return token;
	}

	while (isPresentInDelim(delim, data[i]) == 0)
	{
		token.concatEqual(data[i]);
		i++;
	}
	remove(1, i + 1);
	return token;
}
void CString::operator = (const CString &ref)
{
	if (this == &ref)
		return;
	this->~CString();
	size = ref.size;
	data = new char[size];
	int i;
	for (i = 0; ref.data[i] != '\0'; i++)
	{
		data[i] = ref.data[i];

	}
	data[i] = '\0';



}
int CString::isEqual(const CString & s2) const
{
	int l1 = getLenght();
	int l2 = s2.getLenght();

	if (l1 != l2)
	{
		return 0;

	}
	bool flag = true;
	int i = 0;
	while (flag&&data[i] != '\0')
	{
		if (data[i] != s2.data[i])
		{
			flag = false;
		}
		else
			i++;
	}
	return flag;

}
int CString::isEqual(const char * const s2)
{
	int l1 = getLenght();
	int l2;
	for (l2 = 0; s2[l2] != '\0'; l2++)
	{
	}
	if (l1 != l2)

		return 0;


	bool flag = true;
	int i = 0;
	while (flag&&data[i] != '\0')
	{
		if (data[i] != s2[i])
		{
			flag = false;
		}
		else
			i++;
	}
	return flag;
}
CString::CString(const CString & ref)
{
	size = ref.size;
	data = new char[size];
	int i;
	for (i = 0; ref.data[i] != '\0'; i++)
	{
		data[i] = ref.data[i];

	}
	data[i] = '\0';


}
void CString::operator +=(const char * const s2)
{
	int l = getLenght();
	insert(l + 1, s2);

}
int CString::operator == (const char * const s2)
{
	int l1 = getLenght();
	int l2;
	for (l2 = 0; s2[l2] != '\0'; l2++)
	{
	}
	if (l1 != l2)
	{
		return 0;
	}


	bool flag = true;
	int i = 0;
	while (flag&&data[i] != '\0')
	{
		if (data[i] != s2[i])
		{
			flag = false;
		}
		else
			i++;
	}
	return flag;
}
void CString::operator +=(const CString& s2)
{
	if (this == &s2)
		return;
	int l = getLenght();
	insert(l + 1, s2.data);

}
char & CString::operator [] (const int index)
{
	return data[index];

}
const char & CString::operator [] (const int index)const
{
	return data[index];

}
void CString::concatEqual(const char * const s2)
{

	int l = getLenght();
	insert(l + 1, s2);

}
void CString::reverse()
{

}
void CString::makeLower()
{
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i] >= 'A'&&data[i] <= 'Z')
		{
			data[i] = data[i] + 32;
		}
	}

}
void CString::makeUpper()
{
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (data[i] >= 'a'&&data[i] <= 'z')
		{
			data[i] = data[i] - 32;
		}
	}
}
void CString::trimRight()
{
	int l = getLenght();
	while (data[l - 1] == ' ')
	{
		remove(l, 1);
		l--;
	}
	//remove(l, 1);
}
void CString::trimLeft()
{
	while (data[0] == ' ')
	{
		remove(1, 1);
	}

}
void CString::trim()
{
	trimRight();
	trimLeft();

}
int CString::replace(const char old, const char newC)
{
	int index = find(old, 0);
	cout << index << endl;
	remove(index, index);
	insert(index, newC);
	return 1;


}
int CString::replace(const char * const old, const char *const newC)
{
	int l1;
	for (l1 = 0; old[l1] != '\0'; l1++)
	{
	}
	int l2;
	for (l2 = 0; newC[l2] != '\0'; l2++)
	{
	}
	if (l1 != l2)
	{
		return 0;
	}

	else
	{
		int i = find(old, 0);

		remove(i, l1);
		insert(i, newC);
		return 1;

	}
}
int CString::remove(const char ch)
{
	int j;
	int k;
	for (int i = 0; data[i] != '\0'; i++)
	{

		k = 0;
		j = i;
		while (data[j] == ch)
		{
			k++;
			j++;
		}
		j = i;
		if (data[j] == ch)
		{

			remove(j + 1, k);
		}
	}
	return 1;
}
int CString::remove(const int index, const int count = 1)
{
	int position = index + count - 1;
	int index1 = index - 1;
	int i;
	for (i = index; data[i] != '\0'; i++)
	{
		data[index1] = data[position];
		index1++;
		position++;
	}
	data[i - 1] = '\0';
	return 1;
}
int CString::insert(const int index, const char ch)
{
	int length = getLenght();
	for (int i = length; i >= index; i--)
	{
		data[i] = data[i - 1];

	}
	data[index - 1] = ch;
	data[length + 1] = '\0';
	return 1;

}
int CString::insert(const int index, const char * const substr)
{
	int length = getLenght();
	int subsl;
	for (subsl = 0; substr[subsl] != '\0'; subsl++)
	{
	}
	int index1 = index;
	if (index1 > 0)
	{
		index1 = index1 - 1;
	}
	if (length > 0)
	{
		length = length - 1;
	}
	int newindex = length + subsl;
	int loop = newindex - index;

	for (int i = 0; i <= loop; i++)
	{
		while (length + subsl >= size - 1)
		{
			//at() = '\0';
			resize(size * 2);
		}
		data[length + subsl] = data[length];
		length = length - 1;
	}
	for (int i = 0; i < subsl; i++)
	{
		if (index1 >= size - 1)
		{
			at(index1) = '\0';
			resize(size * 2);
		}
		data[index1] = substr[i];
		index1++;
	}
	data[newindex + 1] = '\0';
	/*data[2] = substr[0];
	data[3] = substr[1];*/
	return 1;


}
int CString::find(const char ch, const int start = 0) const
{
	int i;
	for (i = 0; data[i] != '\0'; i++)
	{
		if (data[i] == ch)
		{
			return i;
		}
	}
	if (data[i] == '\0')
	{
		return -1;
	}
}
int CString::find(const char * const substr, const int start = 0) const
{


	int i;
	int l;
	for (i = 0; substr[i] != '\0'; i++)
	{
	}
	int j = 0;
	int k = 0;
	int m;
	bool flag = true;
	while (data[j] != '\0')
	{
		flag = true;
		if (data[j] == substr[0])
		{
			m = 0;
			l = j;
			k = 0;
			while (flag == true && substr[m] != '\0')
			{
				if (data[l] == substr[m])
				{
					k++;
				}
				else
				{
					flag = false;
				}
				l++;
				m++;
			}
			if (k == i)
			{

				return j + 1;
				break;
			}
		}
		j = j + 1;
	}
}
int CString::getLenght() const
{
	int i;
	for (i = 0; data[i] != '\0'; i++)
	{

	}
	return i;
}
int CString::isEmpty() const
{
	if (data[0] == '\0')
		return 1;
	return 0;


}
char & CString::at(const int index)
{
	return data[index];
}
const char &  CString::at(const int index) const
{
	return data[index];
}
void CString::display()const
{
	cout << data << endl;
}
CString ::operator int()
{
	int num = 0;
	int i = 0;
	while (data[i] != '\0')
	{
		if (data[i] >= '0'&&data[i] <= '9')
			num = num * 10 + (data[i] - '0');
		else
			return -1;
		i++;
	}
	return num;
}
CString ::~CString()
{
	if (data)
	{
		delete[] data;
	}
	data = nullptr;
	size = 0;
}
void CString::concatEqual(const CString & ref)
{
	int l = getLenght();
	insert(l + 1, ref.data);
}
void CString::resize(int newsize)
{
	char* data1 = new char[newsize];
	int i;
	for (i = 0; data[i] != '\0'; i++)
	{
		data1[i] = data[i];

	}
	data1[i] = '\0';
	this->~CString();
	data = data1;
	size = newsize;
	//cout << data1 << endl;
}
CString CString::operator () (const char * const delim)
{
	CString token;

	int i = 0;
	while (isPresentInDelim(delim, data[i]) == 0)
	{
		token += data[i];
		i++;
	}
	remove(1, i + 1);
	return token;

}
CString::CString()
{
	size = 5;
	data = new char[size];
	data[0] = '\0';
}
bool CString::compareStrings(const CString & ref)
{
	if (getLenght() != ref.getLenght())
	{
		return 0;
	}
	else
	{
		int i = 0;
		while (at(i) == ref.at(i) && at(i) != '\0')
		{
			i++;
		}
		if (at(i) == '\0')
		{
			return 1;
		}
		else
			return 0;

	}

}
void CString::input()
{
	int i = 0;
	int j = 0;
	cin.get(at(i));
	i++;
	while (at(j) != '\n')
	{
		cin.get(at(i));

		j++;
		i++;
		if (i >= size - 1)
		{

			at(i) = '\0';
			resize(size * 2);
		}

	}
	at(j) = '\0';
}
CString::CString(const char * const ch)
{
	//cout << ch << endl;
	size = 5;
	data = new char[size];
	int i = 0;
	int l;
	for (l = 0; ch[l] != '\0'; l++)
	{
	}

	while (ch[i] != '\0')
	{

		at(i) = ch[i];
		i++;
		if (i >= size - 1)
		{
			at(i) = '\0';
			resize(size * 2);
		}
	}
	at(i) = '\0';

}
CString::CString(const char c)
{
	size = 2;
	data = new char[size];
	at(0) = c;
	at(1) = '\0';

}




