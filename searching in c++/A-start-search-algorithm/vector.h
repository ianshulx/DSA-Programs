#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
using namespace std;
template <typename objects>
class vector
{
private:
	int thesize;
	int thecapacity;
	objects* object;
public:
	explicit vector(int size = 0) :thesize(size), thecapacity(size + 4), object(new objects[thecapacity])
	{}
	void push_back(const objects&);
	void popback();
	void reserve(int);
	void print();
	int size() const;
	void clear();
	objects& operator[](int);
	typedef objects* iterator;
	iterator begin()
	{
		return &object[0];
	}
	iterator end()
	{
		return &object[thesize];
	}
};
template <typename objects>
void vector<objects>::push_back(const objects& that)
{
	if (this->thesize == thecapacity)
		reserve(2 * thecapacity + 1);
	object[thesize++] = that;
}
template <typename objects>
void vector<objects>::clear()
{
	delete[] object;
	object = NULL;
	thesize = 0;
	thecapacity = 4;
}
template <typename objects>
void vector<objects>::popback()
{
	if (thesize == 0)
		return;
	--thesize;
}
template <typename objects>
void vector<objects>::reserve(int newcapacity)
{
	if (newcapacity < thecapacity)
		return;
	objects* oldarray = new objects[newcapacity];
	for (size_t i = 0; i < thesize; i++)
		oldarray[i] = object[i];
	thecapacity = newcapacity;
	delete[] object;
	object = oldarray;
}
template <typename objects>
void vector<objects>::print()
{
	for (size_t i = 0; i < thesize; i++)
	{
		cout << object[i] << endl;
	}
}
template <typename objects>
objects& vector<objects>::operator[](int i)
{
	return object[i];
}
template <typename objects>
int vector<objects>::size() const
{
	return this->thesize;
}

#endif // !VECTOR_


