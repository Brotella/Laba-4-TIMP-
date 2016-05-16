#include <iostream>

using namespace std;

int fRoot(const int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == -1)
			return i;
	}
	return -1;
}

void direct(const int *arr, int n, int father)
{
	if (father == -1)
		father = fRoot(arr, n);
	cout << father << " ";
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == father)
			direct(arr, n, i);
	}
}

void reverse(const int *arr, int n, int father)
{
	if (father == -1)
		father = fRoot(arr, n);
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == father)
			reverse(arr, n, i);
	}
	cout << father << " ";
}

void symmet(const int *arr, int n, int father)
{
	if (father == -1)
		father = fRoot(arr, n);
	int index = 0;
	for (; index < n; ++index)
	{
		if (arr[index] == father)
		{
			symmet(arr, n, index++);
			break;
		}
	}
	cout << father << " ";
	for (; index < n; ++index)
	{
		if (arr[index] == father)
			symmet(arr, n, index);
	}
}

int main()
{
	int n;
	cin >> n;
	int *cursors = new int[n];
	for (int i = 0; i < n; ++i)
	cin >> cursors[i];
	direct(cursors, n, -1);
	cout << endl;
	reverse(cursors, n, -1);
	cout << endl;
	symmet(cursors, n, -1);
	cout << endl;
	return 0;
}