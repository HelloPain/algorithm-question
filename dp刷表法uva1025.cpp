#include <iostream>
#include <algorithm>
#define INF 1<<20
using namespace std;
int n, T, M1, M2;
int betweenT[75];
bool hastrain[210][75][2];//[时刻][车站][顺1逆2]
int d[210][75];//[i][j]从i时刻起在[j]车站最少还需要的时间
void dp()
{
	for (int i=1; i < n; i++)
		d[T][i] = INF;//T时刻在除了n的车站以外就已经失败
	d[T][n] = 0;
	//边界条件完
	for(int t=T-1;t>=0;t--)
		for (int j = 1; j <= n; j++)
		{
			d[t][j] = d[t + 1][j] + 1;//原站等待
			if (j < n&&hastrain[t][j][1] && t + betweenT[j]<=T)//顺
				d[t][j] = min(d[t][j] , d[t + betweenT[j]][j+1]);
			if (j>1&&hastrain[t][j][2] && t + betweenT[j-1]<=T)//逆
				d[t][j] = min(d[t][j], d[t + betweenT[j-1]][j - 1]);
		}
	if (d[0][1] >= INF)
		printf("no");
	else
		printf("%d", d[0][1]);
}
int main()
{
	cin >> n >> T;
	memset(betweenT, 0, sizeof(betweenT));
	betweenT[0] = betweenT[n] = 0;
	for (int i = 1; i < n; i++)
		cin >> betweenT[i];//i~i+1号车站的时间
	memset(hastrain, 0, sizeof(hastrain));
	cin >> M1;
	for (int i = 0; i < M1; i++)
	{
		int t;
		cin >> t;
		for (int i = 0; i < n; i++)
			hastrain[t + betweenT[i]][i+1][1] = 1;
	}
	cin >> M2;
	for (int i = 0; i < M2; i++)
	{
		int t;
		cin >> t;
		for (int i = n; i >0; i--)
			hastrain[t + betweenT[i]][i][2] = 1;
	}
	dp();
	system("pause");
	return 0;
}