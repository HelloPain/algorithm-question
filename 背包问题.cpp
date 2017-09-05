#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 100

int W[MAXN], P[MAXN], M[MAXN];
int w, n;//w����������n��Ʒ����
//01����f[i][j]=max(f[i-1][j-Wi]+Pi,f[i-1][j])
void dack01()//01����way1
{
	int dp[MAXN][MAXN];
	memset(dp, 0, sizeof(dp));
	//��ʼ����ǡ��װ��dp[0][0]=0,dp[0][else]=-INF��dp[else][0]=-INF;��Ҫ��ǡ��װ������dp����0
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
void back02()//�Ż��ռ临�Ӷ�//01����way2
{
	int dp[MAXN] = { 0 };
	//��ʼ����ǡ��װ��dp[0]=0,dp[else]=-INF;��Ҫ��ǡ��װ������dp����0
	//��Ϊ��ʼ״̬��0����Ʒ�����Ȩ�أ���������dp[0]����ʱ���޷���װ��
	for(int i=1;i<=n;i++)
		for (int j = w; j >= W[i]; j--)
				dp[j] = max(dp[j], dp[j - W[i]] + P[i]);
	cout << dp[w];
}
//��ȫ�������⣺1.f[i][j]=max(f[i-1][j],f[i-1][j-kWi]+kPi)
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
//W[i]����Ʒ����P[i]��ߵ���Ʒ��������ɸ��
//W[i]>�ܵ�w����Ʒ��������ɸ��
//���Ӷ�O��n^2)
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
//���ر�������
int f[MAXN];
void ZeroOneBack(int cost,int price,int v)//01��������һ����Ʒ
{
	for (int i = v; i >= cost; i--)
		f[i] = max(f[i], f[i - cost] + price);
}
void CompeletOneBack(int cost, int price, int v)//��ȫ��������һ����Ʒ
{
	for (int i = cost; i <= v; i++)
		f[i] = max(f[i], f[i - cost] + price);
}
void MultiBack()//���ر���//�������Ż����ѵ�
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