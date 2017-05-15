#include "stdafx.h"
#include "LinkedList.h"

template <class T>
struct LinkedList<T>::Node {
	T value;
	Node *next;
	Node(const T& value) : value(value), next(nullptr)
	{

	}
};

template <class T>
LinkedList<T>::LinkedList()
{
	_size = 0;
	head = tail = nullptr;
}

template <class T>
int LinkedList<T>::size() const
{
	return _size;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
	return head == nullptr;
}

template <class T>
std::string LinkedList<T>::toString() const
{
	Node* tmp = tail;
	string result = "";
	while (tmp != nullptr)
	{
		result.append(to_string(tmp->value));
		result.append(" ");
		tmp = tmp->next;
	}
	return result;
}

template <class T>
bool LinkedList<T>::push(const T& value)
{
	try {
		if (isEmpty())
			head = tail = new Node(value);
		else
		{
			Node* tmp = new Node(value);
			tmp->next = tail;
			tail = tmp;
		}
		_size++;
		return true;
	}
	catch (...)
	{
		return false;
	}
}

template <class T>
T LinkedList<T>::pop()
{
	if (!isEmpty())
	{
		T result = tail->value;
		Node* tmp = tail->next;
		delete tail;
		tail = tmp;
		_size--;
		return result;
	}
	return 0;
}

template <class T>
T LinkedList<T>::peek() const
{
	if (!isEmpty())
		return tail->value;
	return 0;
}

template <class T>
T LinkedList<T>::get(int index) const
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp = tail;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		return tmp->value;
	}
	return 0;
}

template <class T>
bool LinkedList<T>::set(int index, const T& value)
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp = tail;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		tmp->value = value;
		return true;
	}
	return false;
}

template <class T>
bool LinkedList<T>::insertAt(int index, const T& value)
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp = tail;
		for (int i = 0; i < index; i++)
		{
			tmp = tmp->next;
		}
		Node *nd = new Node(value);
		nd->next = tmp->next;
		tmp->next = nd;
		_size++;
		return true;
	}
	return false;
}

template <class T>
bool LinkedList<T>::removeAt(int index)
{
	if (index < _size)
	{
		index = _size - index;
		Node* tmp;
		if (index == 1)
		{
			tmp = tail->next;
			delete tail;
			tail = tmp;
			_size--;
			return true;
		}
		tmp = tail;
		for (int i = 0; i < index-1; i++)
		{
			tmp = tmp->next;
		}
		Node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
		return true;
	}
	return false;
}

template <class T>
LinkedList<T>::~LinkedList()
{
	Node* tmp = tail;
	while (tmp != nullptr)
	{
		tail = tmp->next;
		delete tmp;
		tmp = tail;
	}
}