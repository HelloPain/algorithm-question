#include <iostream>
#include <algorithm>
#define MAXN 100
using namespace std;
int n;
int d[MAXN];//从节点i出发的最长路径
int a[MAXN], b[MAXN];
int G[MAXN][MAXN];//邻接表
int dp(int i)
{
	int &ans = d[i];//为d[i]声明一个引用
	if (ans > 0)return ans;
	ans = 1;//至少长度为1啦……
	for (int j = 0; j < n; j++)
	{
		if (G[i][j])
			ans = max(ans, dp(j)+1);
	}
	return ans;
}
void build()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)	
			if ((a[i] < a[j] && b[i] < b[j]) || (a[i] < b[j] && b[i] < a[j]))
				G[i][j] = 1;
}

void print(int i)//递归输出
{
	cout << i;
	for (int j = 0; j < n; j++)//保证字典序最小
		if (G[i][j] && d[i] == d[j] + 1)
		{
			print(j);
			break;
		}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	memset(d, 0, sizeof(d));
	memset(G, 0, sizeof(G));
	build();
	dp(0);
	int Max = 0, Mi = 0;
	for (int i = 0; i < n; i++)
	{
		if (Max < d[i])
		{
			Max = d[i]; Mi = i;
		}
	}
	//print(0);
	cout << Max;
	system("pause");
	return 0;
}