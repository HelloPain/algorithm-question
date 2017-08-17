#include <iostream>

using namespace std;
const int maxn = 100;
int sum[maxn] = { 0 };

void build(int p)
{
	int v; cin >> v;
	if (v == -1)return;
	sum[p] += v;
	build(p - 1); build(p + 1);
}
bool init()
{
	int v; cin >> v;
	if (v == -1)return false;
	int pos = maxn / 2;
	sum[pos] = v;
	build(pos - 1); build(pos + 1);
}
int main()
{
	int kase = 0;
	while (init())
	{
		int p = 0;
		while (sum[p] == 0)p++;//找到最左边的叶子
		cout << "Case " << ++kase << ":\n" << sum[p++];
		while (sum[p])cout << ' ' << sum[p++];
	}
	system("pause");
	return 0;
}