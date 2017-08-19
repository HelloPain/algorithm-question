#include <iostream>
#include <queue>
#define MAXN 105
using namespace std;
char maze[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m;
typedef struct point
{
	int x, y,t;
	point(int xx, int yy,int tt) :x(xx), y(yy),t(tt) {};
}point;
queue<point> q;
int sx, sy;
int dir[8] = { 0,1,0,-1,1,0,-1,0 };
int ans = -1;
void bfs()
{
	q.push(point(sx, sy,0));
	vis[sx][sy] = 1;
	while (!q.empty())
	{
		point p = q.front();
		if (maze[p.x][p.y] == 'T')
		{
			ans = p.t; return;
		}
		for (int i = 0; i < 8; i+=2)
		{
			int a = p.x + dir[i]; int b = p.y + dir[i + 1];
			if (a >= 0 && b >= 0 && a < n&&b < m&&maze[a][b] != '#' && !vis[a][b])
			{
				q.push(point(a, b,p.t+1));
				vis[a][b] = 1;
			}
		}
		q.pop();
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j= 0; j < m; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'S')
			{
				sx = i; sy = j;
			}
		}
	bfs();
	cout << ans;
	system("pause");
	return 0;
}