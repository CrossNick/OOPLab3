#include "stdafx.h"
#include "Queue.h"

template <class T>
struct Queue<T>::Node {
	T value;
	Node *next;
	Node(const T& value) : value(value), next(nullptr)
	{

	}
};

template <class T>
Queue<T>::Queue()
{
	_size = 0;
	head = tail = nullptr;
}

template <class T>
int Queue<T>::size() const
{
	return _size;
}

template <class T>
bool Queue<T>::isEmpty() const
{
	return head == nullptr;
}

template <class T>
std::string Queue<T>::toString() const
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
bool Queue<T>::push(const T& value)
{
	try {
		if (isEmpty())
			head = tail =  new Node(value);
		else
		{
			tail->next = new Node(value);
			tail = tail->next;
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
T Queue<T>::pop()
{
	if (!isEmpty())
	{
		T result = head->value;
		Node* tmp = head->next;
		delete head;
		head = tmp;
		_size--;
		return result;
	}
	throw "The Queue is empty!";
}

template <class T>
T Queue<T>::peek() const
{
	if (!isEmpty())
		return head->value;
	throw "The Queue is empty!";
}

template <class T>
Queue<T>::~Queue()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = tmp->next;
		delete tmp;
		tmp = head;
	}
}
