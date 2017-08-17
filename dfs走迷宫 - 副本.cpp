#include <iostream>
using namespace std;

int m, n;
const int maxn = 100;
char Map[maxn][maxn];
int id[maxn][maxn] = { 0 };//×ö±ê¼Ç
int cnt = 0;
void dfs(int i, int j)
{
	if (i<0 || i>=n || j<0 || j>=m||Map[i][j] == '#' ||id[i][j])return;
	if (Map[i][j] == 'T') { cnt++; return; }
	id[i][j] = 1;
	//if (Map[i][j] != '.'&&Map[i][j]!='S')return;
	dfs(i - 1, j);
	dfs(i + 1, j);
	dfs(i, j - 1);
	dfs(i, j + 1);
	id[i][j] = 0;
}

int maina()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> Map[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (Map[i][j] == 'S')
				dfs(i, j);
		}
	}
	cout << cnt;
	system("pause");
	return 0;
}