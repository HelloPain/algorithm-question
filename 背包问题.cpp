#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100

int W[MAXN], P[MAXN], M[MAXN];
int w, n;//w背包容量，n物品个数
//01背包f[i][j]=max(f[i-1][j-Wi]+Pi,f[i-1][j])
void dack01()//01背包way1
{
	int dp[MAXN][MAXN];
	memset(dp, 0, sizeof(dp));
	//初始化：恰好装满dp[0][0]=0,dp[0][else]=-INF，dp[else][0]=-INF;不要求恰好装满就是dp都是0
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= w; j++)
		{
			if (j >= W[i])
				dp[i][j] = max(dp[i - 1][j - W[i]] + P[i], dp[i - 1][j]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	cout << dp[n][w];
}
void back02()//优化空间复杂度//01背包way2
{
	int dp[MAXN] = { 0 };
	//初始化：恰好装满dp[0]=0,dp[else]=-INF;不要求恰好装满就是dp都是0
	//因为初始状态是0件物品的最高权重，其他除了dp[0]其他时候无法被装满
	for(int i=1;i<=n;i++)
		for (int j = w; j >= W[i]; j--)
				dp[j] = max(dp[j], dp[j - W[i]] + P[i]);
	cout << dp[w];
}
//完全背包问题：1.f[i][j]=max(f[i-1][j],f[i-1][j-kWi]+kPi)
//2.f[i][j]=max(f[i-1][j],f[i][j-W[i]]+Pi)
void completeback()
{
	int dp[MAXN];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		for (int v = W[i]; v <= w; v++)
			dp[v] = max(dp[v], dp[v - W[i]] + P[i]);
	cout << dp[w];
}
void optimizer()
//W[i]的物品挑出P[i]最高的物品，其他的筛掉
//W[i]>总的w的物品，其他的筛掉
//复杂度O（n^2)
{
	for (int i = 0; i < n; i++)
	{
		if (W[i] > w)
			W[i] = P[i] = 0;
		else
		{
			for (int j = 0; j < n; j++)
				if (W[i] == W[j] && P[j] < P[i])
					W[j] = P[j] = 0;
		}
	}
}
//多重背包问题
int f[MAXN];
void ZeroOneBack(int cost,int price,int v)//01背包处理一件物品
{
	for (int i = v; i >= cost; i--)
		f[i] = max(f[i], f[i - cost] + price);
}
void CompeletOneBack(int cost, int price, int v)//完全背包处理一件物品
{
	for (int i = cost; i <= v; i++)
		f[i] = max(f[i], f[i - cost] + price);
}
void MultiBack()//多重背包//二进制优化是难点
{
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; i++)
	{
		if (M[i] * W[i] > w)
			CompeletOneBack(W[i], P[i], w);
		else
		{
			for (int k = 1; k < M[i]; M[i]-=k,k <<= 1)
				ZeroOneBack(k*W[i], k*P[i], w);
			ZeroOneBack(M[i] * W[i], M[i] * P[i], w);
		}
	}
}
int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
		cin >> P[i] >> W[i];
	completeback();
	
	
	system("pause");
	return 0;
}