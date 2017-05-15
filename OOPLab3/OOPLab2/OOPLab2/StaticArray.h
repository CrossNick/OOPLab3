#pragma once
#include "IndexedContainer.h"

template<class T>
class StaticArray : public IndexedContainer<T>
{
private:
	T* arr;
	int _size;
public:
	StaticArray(int sz);
	StaticArray(const StaticArray<T>& st);
	StaticArray<T>& operator=(const StaticArray<T>& st);
	int size() const override;
	bool isEmpty() const override;
	T get(int index) const override;
	T& get(int index) override;
	bool set(int index, const T& value) override;

	//итератор
	template <class S>
	class ArrayIterator : public JavaIterator<S>
	{
	private:
		friend class StaticArray<S>;
		int current;
		int size;
		S* arr;
	public:
		ArrayIterator(S* arr, int size):
			arr(arr), size(size)
		{
			current = 0;
		}
		bool hasNext() override {
			return current<size-1;
		}
		S& next() override {
			S& tmp = arr[current];
			++current;
			return tmp;
		}
	};

	//константный итератор
	template <class S>
	class ArrayConstIterator : public JavaIterator<S>
	{
	private:
		friend class StaticArray<S>;
		int current;
		int size;
		S* arr;
	public:
		ArrayConstIterator(S* arr, int size) :
			arr(arr), size(size)
		{
			current = 0;
		}
		bool hasNext() override {
			return current<size;
		}
		const S& next() override {
			S& tmp = arr[current];
			++current;
			return tmp;
		}
	};


	friend class ArrayIterator<T>;
	friend class ArrayConstIterator<const T>;
	JavaIterator<T> *createIterator() override;
	JavaIterator<const T> *createConstIterator() const override;
	virtual ~StaticArray();
};

template<class T>
JavaIterator<T>* StaticArray<T>::createIterator()
{
	return new ArrayIterator<T>(arr, _size);
}
template<class T>
JavaIterator<const T>* StaticArray<T>::createConstIterator() const
{
	return new ArrayConstIterator<const T>(arr, _size);
}

template<class T>
StaticArray<T>::StaticArray(int sz)
{
	_size = sz;
	arr = new T[_size];
}

template<class T>
StaticArray<T>::StaticArray(const StaticArray<T>& st)
{
	arr = new T[st.size()];
	_size = st.size();
	auto iter = st.createConstIterator();
	int ind = 0;
	while (iter->hasNext())
	{
		set(ind++, iter->next());
	}
}

template<class T>
StaticArray<T>& StaticArray<T>::operator=(const StaticArray<T>& st)
{
	delete[] arr;
	arr = new T[st.size()];
	_size = st.size();
	auto iter = st.createConstIterator();
	int ind = 0;
	while (iter->hasNext())
	{
		set(ind++, iter->next());
	}
	return *this;
}

template<class T>
int StaticArray<T>::size() const
{
	return _size;
}

template<class T>
bool StaticArray<T>::isEmpty() const
{
	return _size == 0;
}


template<class T>
T StaticArray<T>::get(int index) const
{
	if (index<_size)
		return arr[index];
	throw "The Array is empty!";
}

template<class T>
T& StaticArray<T>::get(int index)
{
	if (index<_size)
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
	return false;
}

template<class T>
StaticArray<T>::~StaticArray()
{
	delete[] arr;
}
