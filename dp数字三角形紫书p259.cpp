#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 1005
using namespace std;
int d[MAXN][MAXN];//d[i][j]表示从底层到(i,j)这个点的最大和
int a[MAXN][MAXN];//读入值
int n;//层数
int solve1(int i,int j)//纯递归，O(2^n)
{
	return a[i][j]+(i == n ? 0 : max(solve1(i + 1, j), solve1(i + 1, j + 1)));
}//如果是最后一层就不用往下面走

int solve2(int i, int j)//循环，O(n^2)
{
	for (int j = 1; j <= n; j++)//先算出最后一层的d[n][j],其实就是a[n][j]
		d[n][j] = a[n][j];
	for (int i = n - 1; i > 0; i++)//倒着算出d[i][j]
		for (int j = 1; j <=i; j++)
			d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
	//算d[i][j]所需要的d[i+1][j]和d[i+1][j+1]已经算出来了
}

int solve3(int i, int j)//记忆型递归，通过标记d[i][j]避免重复计算,O(n^2)
{
	if(i==1)memset(d, -1, sizeof(d));
	if (d[i][j] > 0)return d[i][j];
	return d[i][j]=a[i][j] + (i == n ? 0 : max(solve3(i + 1, j), solve3(i + 1, j + 1)));
	//赋值语句具有返回值
}

int main()
{
	
	system("pause");
	return 0;
}