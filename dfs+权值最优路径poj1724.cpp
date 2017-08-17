#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K, N, R;//K是总钱数,N是城市数，R是路数,从城市1走到城市N,而且要求不重复
int minLen = 1 << 30;
int Len = 0;
int money = 0;
int mid[110][10010] ;//走到城市i正好花了j元的情况下总路程为mid[i][j]
struct road
{
	int d, p, l;
};
vector<vector<road>> G(110);//储存道路信息的类邻接表
int vis[110] = { 0 };
void dfs(int s)//从s出发
{
	if (s == N)//走到终点
		minLen = min(Len, minLen);
	else
	{
		for (int i = 0; i < G[s].size(); i++)
		{
			road r = G[s][i];
			if (r.p + money > K||r.l+Len>minLen || r.l + Len>mid[r.d][r.p + money])//剪枝
				continue;//继续寻找下一条路
			money += r.p;
			Len += r.l;
			vis[r.d] = 1;
			mid[r.d][money] = Len;
			dfs(r.d);
			money -= r.p;
			Len -= r.l;
			vis[r.d] = 0;
		}
	}
}
int main()
{
	cin >> K >> N >> R;
	road r;
	int s;
	for (int i = 0; i < R; i++)
	{
		cin >> s >> r.d >> r.l >> r.p;
		G[s].push_back(r);
	}
	vis[1] = 1;
	//memset(mid, 1<<30, sizeof(mid));//问题所在：为什么不能正常赋值？？
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < 10010; j++)
			mid[i][j] = 1 << 30;
	dfs(1);
	if (minLen != 1 << 30)
		cout << minLen;
	else
		cout << -1;
	cout << '\n';
	system("pause");
	return 0;
}