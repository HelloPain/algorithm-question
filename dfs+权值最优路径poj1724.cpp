#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int K, N, R;//K����Ǯ��,N�ǳ�������R��·��,�ӳ���1�ߵ�����N,����Ҫ���ظ�
int minLen = 1 << 30;
int Len = 0;
int money = 0;
int mid[110][10010] ;//�ߵ�����i���û���jԪ���������·��Ϊmid[i][j]
struct road
{
	int d, p, l;
};
vector<vector<road>> G(110);//�����·��Ϣ�����ڽӱ�
int vis[110] = { 0 };
void dfs(int s)//��s����
{
	if (s == N)//�ߵ��յ�
		minLen = min(Len, minLen);
	else
	{
		for (int i = 0; i < G[s].size(); i++)
		{
			road r = G[s][i];
			if (r.p + money > K||r.l+Len>minLen || r.l + Len>mid[r.d][r.p + money])//��֦
				continue;//����Ѱ����һ��·
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
	//memset(mid, 1<<30, sizeof(mid));//�������ڣ�Ϊʲô����������ֵ����
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