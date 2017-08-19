#include <iostream>
#include <queue>
#define MAXN 5005
using namespace std;
int n, a, b;
typedef struct point
{
	int x;//坐标
	int t;//走到这里的步数
	point(int xx, int tt) :x(xx), t(tt) {};
}point;
queue<point> q;
int vis[MAXN];
void bfs()
{
	q.push(point(a, 0));
	vis[a] = 1;
	while (!q.empty())
	{
		point p = q.front();
		if (p.x == b)
		{
			cout << p.t; return;
		}
		if (p.x + 1 < n&&!vis[p.x+1])
		{
			q.push(point(p.x + 1, p.t + 1));
			vis[p.x + 1] = 1;
		}
		if (p.x - 1 >= 0&&!vis[p.x - 1])
		{
			q.push(point(p.x - 1, p.t + 1));
			vis[p.x - 1] = 1;
		}
		if (p.x *2<=n&&!vis[p.x*2])
		{
			q.push(point(p.x *2, p.t + 1));
			vis[p.x*2] = 1;
		}
		q.pop();
	}
}
int main()
{
	cin >> n >> a >> b;
	bfs();
	system("pause");
	return 0;
}