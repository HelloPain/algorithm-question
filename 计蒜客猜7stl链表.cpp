#include <iostream>
#include <string>
#include <list>
#define N 7
using namespace std;
string name[1005];
int n, m, t;
list<string> List;
bool has7(int i)
{
	while(i>0)
	{
		int x = i % 10;
		if (x == 7)
			return true;
		i /= 10;
	}
	return false;
}
void solve()
{
	list<string>::iterator it = List.begin();
	for (int i=t; List.size() > 1; i++)
	{
		int f = 0; list<string>::iterator del;
		if (i % 7 == 0 || has7(i))
		{
			del = it; f = 1;
		}
		 if (it == (--List.end()))
			it = List.begin();
		else
			it++;
		if (f)
			List.erase(del);
	}
}
int main()
{
	cin >> n >> m >> t;
	getchar();
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < m-1 )
			cin >> name[j++];
		else
		{
			string tmp;
			cin >> tmp;
			List.push_back(tmp);
		}
	}
	for (int i = 0; i < m-1; i++)
	{
		List.push_back(name[i]);
	}
	solve();
	cout << List.front();
	system("pause");
	return 0;
}