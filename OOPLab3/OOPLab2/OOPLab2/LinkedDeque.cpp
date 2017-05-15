#include "stdafx.h"
#include "LinkedDeque.h"

template <class T>
struct LinkedDeque<T>::Node{
	T value;
	Node *next;
	Node *prev;
	Node(const T& value) : value(value), next(nullptr), prev(nullptr)
	{
	}
};

template <class T>
LinkedDeque<T>::LinkedDeque():_size(0), head(nullptr), tail(nullptr)
{
}

template <class T>
int LinkedDeque<T>::size() const
{
	return _size;
}
template <class T>
bool LinkedDeque<T>::isEmpty() const
{
	return _size == 0;
}

template <class T>
std::string LinkedDeque<T>::toString() const
{
	Node* tmp = head;
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
bool LinkedDeque<T>::pushFront(const T& value)
{
	if (isEmpty())
	{
		head = tail = new Node(value);
		_size++;
		return true;
	}
	else
	{
		head->prev = new Node(value);
		Node *tmp = head;
		head = head->prev;
		head->next = tmp;
		_size++;
		return true;
	}
	return false;
}

template <class T>
bool LinkedDeque<T>::pushBack(const T& value)
{
	if (isEmpty())
	{
		head = tail = new Node(value);
		_size++;
		return true;
	}
	else
	{
		tail->next = new Node(value);
		Node *tmp = tail;
		tail = tail->next;
		tail->prev = tmp;
		_size++;
		return true;
	}
	return false;
}

template <class T>
T LinkedDeque<T>::popFront()
{
	T result = head->value;
	Node* tmp = head->next;
	delete head;
	head = tmp;
	_size--;
	return result;
}

template <class T>
T LinkedDeque<T>::popBack()
{
	T result = tail->value;
	Node* tmp = tail->prev;
	delete tail;
	tail = tmp;
	_size--;
	return result;
}

template <class T>
T LinkedDeque<T>::peekFront() const
{
	return head->value;
}

template <class T>
T LinkedDeque<T>::peekBack() const
{
	return tail->value;
}

template <class T>
LinkedDeque<T>::~LinkedDeque()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = tmp->next;
		delete tmp;
		tmp = head;
	}
}
