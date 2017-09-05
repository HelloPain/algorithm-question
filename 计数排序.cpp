#include <iostream>
#include <vector>
using namespace std;

template<typename Type>
void countSort(vector<Type> &a, Type l, Type u, int n)
{
	vector<Type> c(u - l + 1, 0);
	vector<Type> s(n, 0);

	for (int i = 0; i < n; i++)
		c[a[i]-1]++;//计算频率值

	for (int i = 1; i <= u - l; i++)
		c[i] += c[i - 1];//计算分布值

	for (int i = n-1; i >= 0; i--)
	{
		int j = a[i]-1;
		s[c[j] - 1] = a[i];
		c[j]--;
	}

	for (int i = 0; i < n; i++)
		a[i] = s[i];
}

int main()
{
	vector<int> a;
	a.push_back(3);
	a.push_back(1);
	a.push_back(2);
	a.push_back(4);
	a.push_back(3);
	countSort(a, 1, 4, 5);
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++)
		cout << *it << " ";
	system("pause");
}