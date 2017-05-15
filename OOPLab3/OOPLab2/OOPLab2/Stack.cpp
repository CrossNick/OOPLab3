#include "stdafx.h"
#include "Stack.h"

template <class T>
struct Stack<T>::Node{
	T value;
	Node *next;
	Node(const T& value) : value(value), next(nullptr)
	{	

	}
};

template <class T>
Stack<T>::Stack()
{
	_size = 0;
	head = nullptr;
}

template <class T>
int Stack<T>::size() const
{
	return _size;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return head==nullptr;
}

template <class T>
std::string Stack<T>::toString() const
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
bool Stack<T>::push(const T& value)
{
	try {
		if (isEmpty())
			head = new Node(value);
		else
		{
			Node* tmp = new Node(value);
			tmp->next = head;
			head = tmp;
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
T Stack<T>::pop()
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
	throw "The Stack is empty!";
}


template <class T>
T Stack<T>::peek() const
{
	if (!isEmpty())
		return head->value;
	throw "The Stack is empty!";
}

template <class T>
Stack<T>::~Stack()
{
	Node* tmp = head;
	while (tmp != nullptr)
	{
		head = tmp->next;
		delete tmp;
		tmp = head;
	}
}
