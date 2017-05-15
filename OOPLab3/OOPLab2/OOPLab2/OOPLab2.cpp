// OOPLab2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>

int main()
{
	const int n = 10;
	vector<PushPopContainer<int>*> arr1({ new Stack<int>(), new Queue<int>(), new LinkedList<int>() });
	vector<IndexedContainer<int>*> arr2({new StaticArray<int>(n)});
	vector<Deque<int>*> arr3({ new LinkedDeque<int>()});
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr1.size(); j++)
			arr1[j]->push(i);
		for (int j = 0; j < arr2.size(); j++)
			arr2[j]->set(i,i);
		for (int j = 0; j < arr3.size(); j++)
		{
			arr3[j]->pushBack(i);
			arr3[j]->pushFront(i);
		}
	}
	for (int j = 0; j < arr1.size(); j++)
		cout << arr1[j]->toString() << endl;
	for (int j = 0; j < arr2.size(); j++)
		cout << arr2[j]->toString() << endl;
	for (int j = 0; j < arr3.size(); j++)
		cout << arr3[j]->toString() << endl;

	//проверка T& get(int index)
	cout << endl;
	cout << arr1[2]->toString() << endl;
	dynamic_cast<IndexedContainer<int>*>(arr1[2])->get(2) = -1;
	cout << arr1[2]->toString() << endl;
	cout << endl;

	//проверка итератора
	auto iter = dynamic_cast<StaticArray<int>*>(arr2[0])->createIterator();
	cout << iter->next() << endl;
	iter->next() = -10;
	cout << iter->next() << endl;
	cout << arr2[0]->toString() << endl;

	//проверка  cout
	cout << endl;
	cout << *arr1[1] << endl;

	//проверка сравнения
	cout << endl;
	cout << (*arr1[0] == *arr1[1]) << endl;

	//проверка индексатора
	cout << endl;
	cout << (*arr2[0])[0] << endl;

	//проверка копирования
	Stack<int> s;
	for (int j = 0; j < arr1.size(); j++)
		s.push(j);
	Stack<int> s1(s);
	Stack<int> s2;
	s2 = s;
	s1.pop();
	s2.pop();
	s2.pop();
	cout << s << endl << s1 << endl << s2 << endl << s << endl;
	cout << endl;

	//Проверка сортировки
	Stack<int> ss;
	for (int j = 0; j <10; j++)
		ss.push(j);
	cout << ss << endl;
	ss.Sort();
	cout << ss << endl;
	cout << endl;
	StaticArray<int> ars(10);
	for (int j = 0; j <10;j++)
		ars[j] = 9-j;
	cout << ars << endl;
	ars.Sort();
	cout << ars << endl;
	system("pause");


    return 0;
}

