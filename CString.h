#pragma once
#ifndef CSTRING_H
#define CSTRING_H

class CString
{
	char * data;
	int size;

public:
	void makeUpper();
	void makeLower();
	void trimRight();
	void trimLeft();
	void trim();
	int isEqual(const CString & s2) const;
	CString concat(const CString& s2) const;
	CString right(int count);
	void concatEqual(const CString & s2);
	int remove(const int index, const int count);
	int insert(const int index, const char ch);
	CString();
	CString(const char c);
	void input();
	void resize(int);
	~CString();
	CString(const char * const ch);
	void display()const;
	char & at(const int index);
	const char & at(const int index) const;
	int isEmpty() const;
	CString(const CString &);
	int getLenght() const;
	int find(const char * const substr, const int start) const;
	char & operator [] (const int index);
	const char & operator [] (const int index) const;
	void operator +=(const CString& s2);
	void operator +=(const char * const s2);
	void operator = (const CString &ref);
	int operator == (const char * const s2);
	CString operator () (const char * const delim);
	operator int();
	bool isPresentInDelim(const char *ch, char);
	int insert(const int index, const char * const substr);
	int find(const char ch, const int start)const;
	int remove(const char ch);
	int replace(const char * const old, const char *const newC);
	int replace(const char old, const char newC);
	void reverse();
	bool compareStrings(const CString & ref);
	void concatEqual(const char * const s2);
	int isEqual(const char * const s2);
	CString left(int count);
	CString tokenzier(const char * const delim);
};

#endif 