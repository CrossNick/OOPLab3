#pragma once
#include <string>
#include "JavaIterator.h"
template <class T>
class Container;

template <class T>
std::ostream & operator<<(std::ostream & os, const Container<T> & ct)
{
	os << ct.toString();
	return os;
}

template <class T>
class Container
{
public:
	virtual int size() const = 0;
	virtual bool isEmpty() const;
	virtual std::string toString() const;
	void Sort();
	virtual JavaIterator<T> *createIterator() = 0;
	virtual JavaIterator<const T> *createConstIterator() const = 0;
	friend std::ostream& operator <<<T>(std::ostream & os, const Container& ct);
	bool operator ==(Container const& ct) const;
	virtual ~Container() = 0 {}
};

template <class T>
bool Container<T>::isEmpty() const
{
	return size() == 0;
}

template <class T>
std::string Container<T>::toString() const
{
	std::string result = "";
	auto iter = createConstIterator();
	while (iter->hasNext())
	{
		result.append(to_string(iter->next()));
		result.append(" ");
	}
	return result;
}

template<class T>
inline void Container<T>::Sort()
{
	int ind1 = 1, ind2 = 0;
	auto iter1 = createIterator();
	while (ind1<=size())
	{
		T x = iter1->next();
		ind2 = ind1;
		while (ind2 > 0)
		{
			auto iter3 = createIterator();
			for (int i = 0; i < ind2 - 2; i++)
				iter3->next();
			T x1 = iter3->next();
			if (x1 <= x)
				break;
			iter3->next() = x1;
			delete iter3;
			--ind2;
		}
		auto iter2 = createIterator();
		for (int i = 0; i < ind2 - 1; i++)
			iter2->next();
		iter2->next() = x;
		delete iter2;
		++ind1;
	};
	delete iter1;
}

template<class T>
 bool Container<T>::operator ==(Container const& ct) const
{
	auto iter1 = createConstIterator();
	auto iter2 = ct.createConstIterator();
	while (iter1->hasNext() && iter2->hasNext())
	{
		if (iter1->next() != iter2->next())
			return false;
	}
	if(iter1->hasNext() != iter2->hasNext())
		return false;
	return true;
}


