#include <algorithm>
#include <iostream>
#include <stdio.h>
#include "Windows.h"

#define MIN_VALUE 0
#define MAX_VALUE 100

using namespace std;

int binary_search(int* array, int x, int start, int end, int& count)
{
	if (start == end)
	{
		count++;
		return array[start] == x ? end : -1;
	}
	else
	{
		int mid = (start + end) / 2;
		if (x > array[mid])
		{
			count++;
			return binary_search(array, x, mid + 1, end, count);
		}
		else
		{
			count++;
			return binary_search(array, x, start, mid, count);
		}
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int* array = NULL;
	int n;
	int max = 0;
	int count = 0;
	int index = 0;
	int cmp = 0;


	cout << "Розмір масиву: ";
	cin >> n;
	array = new int[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = (rand() % (MAX_VALUE - MIN_VALUE)) + MIN_VALUE;
	}
	sort(array, array + n);
	cout << "Масив " << n << " елементів: \n";
	for (int i = 0; i < n; ++i)
	{
		cout << array[i] << " ";
	}
	cout << "\n\n";


	max = array[n - 1];
	index = binary_search(array, max, 0, n - 1, cmp);
	count = n - index;
	cout << "Максимальне значення: " << max << "\n";
	cout << "Кількість у масиві: " << count << "\n";
	cout << "Індекс: " << index << "\n";
	cout << "Кількість порівнянь: " << cmp << "\n";

	if (array)
	{
		delete[] array;
		array = NULL;
	}
	return 0;
}