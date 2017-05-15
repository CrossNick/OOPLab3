#include "stdafx.h"
#include "StaticArray.h"


template<class T>
StaticArray<T>::StaticArray(int sz)
{
	_size = sz;
	arr = new T[_size];
}

template<class T>
int StaticArray<T>::size() const
{
	return _size;
}

template<class T>
bool StaticArray<T>::isEmpty() const
{
	return _size ==0;
}

template<class T>
std::string StaticArray<T>::toString() const
{
	string result = "";
	for (int i = 0; i < _size; i++)
	{
		result.append(to_string(arr[i]));
		result.append(" ");
	}
	return result;
}

template<class T>
T StaticArray<T>::get(int index) const
{
	if(index<_size)
		return arr[index];
	throw "The Array is empty!";
}

template<class T>
bool StaticArray<T>::set(int index, const T&  value)
{
	if (index < _size)
	{
		arr[index] = value;
		return true;
	}
	return false	
}

template<class T>
StaticArray<T>::~StaticArray()
{
	delete[] arr;
}
