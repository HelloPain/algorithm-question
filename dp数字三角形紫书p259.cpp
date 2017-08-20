#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXN 1005
using namespace std;
int d[MAXN][MAXN];//d[i][j]��ʾ�ӵײ㵽(i,j)����������
int a[MAXN][MAXN];//����ֵ
int n;//����
int solve1(int i,int j)//���ݹ飬O(2^n)
{
	return a[i][j]+(i == n ? 0 : max(solve1(i + 1, j), solve1(i + 1, j + 1)));
}//��������һ��Ͳ�����������

int solve2(int i, int j)//ѭ����O(n^2)
{
	for (int j = 1; j <= n; j++)//��������һ���d[n][j],��ʵ����a[n][j]
		d[n][j] = a[n][j];
	for (int i = n - 1; i > 0; i++)//�������d[i][j]
		for (int j = 1; j <=i; j++)
			d[i][j] = a[i][j] + max(d[i + 1][j], d[i + 1][j + 1]);
	//��d[i][j]����Ҫ��d[i+1][j]��d[i+1][j+1]�Ѿ��������
}

int solve3(int i, int j)//�����͵ݹ飬ͨ�����d[i][j]�����ظ�����,O(n^2)
{
	if(i==1)memset(d, -1, sizeof(d));
	if (d[i][j] > 0)return d[i][j];
	return d[i][j]=a[i][j] + (i == n ? 0 : max(solve3(i + 1, j), solve3(i + 1, j + 1)));
	//��ֵ�����з���ֵ
}

int main()
{
	
	system("pause");
	return 0;
}