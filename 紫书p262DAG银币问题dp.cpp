#include <iostream>
#include <algorithm>
#define MAXN 100
#define INF 1<<30
using namespace std;
int dmax[MAXN];//�������iԪ����Ҫ��Ӳ�������ֵ
int dmin[MAXN];
int n;
int V[MAXN];//�����������
int vis[MAXN];
int S;
int dp1(int S)//���ñ��������仯��������Сֵͬ��
{
	int &ans = dmax[S];
	if (ans != -1)return ans;//���
	ans = -(1 << 30);//����·��ʱ��
	for (int i = 0; i < n; i++)
		if (S >= V[i])
			ans= max(ans,1+ dp1(S - V[i]));
	return ans;
}

int dp2(int S)//�ñ��������仯��������Сֵͬ��
{
	if (vis[S])return dmax[S];
	vis[S] = 1;
	int& ans = dmax[S];
	ans = -1 << 30;
	for (int i = 0; i < n; i++)
		if (S >= V[i])
			ans = max(ans, 1 + dp2(S - V[i]));
	return ans;
}
void dp3()//����(ѭ��),ͬʱ�����Сֵ�����ֵ
{
	dmax[0] = dmin[0] = 0;
	for (int i = 1; i <= S; i++)
	{
		dmax[i] = -INF; dmin[i] = INF;
	}
	for(int i=1;i<=S;i++)
		for(int j=0;j<n;j++)
			if (V[j] <= i)
			{
				dmin[i] = min(dmin[i], dmin[i - V[j]] + 1);
				dmax[i] = max(dmax[i], dmax[i - V[j]] + 1);
			}
	cout << dmin[S] << ' ' << dmax[S];
}

void print_ans(int *d, int S)//����ֵ�����С�ķ���
{
	for (int i = 0; i < n; i++)
		if (V[i] <= S&&d[S] == d[S - V[i]] + 1)
		{
			printf("%d:%d\n", i + 1, V[i]);
			print_ans(d, S - V[i]);
			break;//break�ǹؼ�,�ҵ��Ͳ�Ҫ������
		}
}

int min_coin[MAXN];
int max_coin[MAXN];
void dp4()//����˳���¼·��
{
	for(int i=1;i<=S;i++)
		for(int j=0;j<n;j++)
			if (i >= V[j])
			{
				if (dmin[i] > dmin[i - V[j]] + 1)
				{
					dmin[i] = dmin[i - V[j]] + 1; min_coin[i] = j;//��¼��i���Ǹ��������j,jΪ�ֵ�����С
				}
				if (dmax[i] < dmax[i - V[j]] + 1)
				{
					dmax[i] = dmax[i - V[j]] + 1; max_coin[i] = j;
				}
			}
}
void print_ans1(int *coin, int S)
{
	while (S)
	{
		printf("%d:%d\n", coin[S], V[coin[S]]);
		S -= V[coin[S]];
	}
}
int main()
{
	memset(dmax, -1, sizeof(dmax));
	memset(vis, 0, sizeof(vis));
	system("pause");
	return 0;
}