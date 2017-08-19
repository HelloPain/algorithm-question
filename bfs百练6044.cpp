#include <iostream>
#include <queue>
#define MAXN 250
using namespace std;
int M, N, T;
char G[MAXN][MAXN];//走过的话标记为a
int W[MAXN][MAXN];//走到[i][j]需要的剩下的最大查克拉
typedef struct node
{
	int r, c, w, t;
	node(int rr, int cc, int ww, int tt) :r(rr), c(cc), w(ww), t(tt) {};
}node;
queue<node> q;
int ans = 1 << 30;
int mr, mc;//起点
int dir1[4] = { 0, 1, 0, -1 };
int dir2[4] = { 1, 0, -1, 0 };

void bfs()
{
	q.push(node(mr, mc, T, 0));
	W[mr][mc] = T;
	while (!q.empty())
	{
		node t = q.front();
		if (G[t.r][t.c] == '+')
		{
			ans = t.t; return;
		}
		for (int i = 0; i < 4; i++)
		{
			int a = t.r + dir1[i]; int b = t.c + dir2[i];
			if (a >= 0 && b >= 0 && a < M&&b < N&&t.w>W[a][b])//当前查克拉大于之前的记录
				//此处查克拉相当于是去重，因为如果走过的话，W会被标记为非负数，并且注意查克拉不会增加只会减少
				//但是加了标记之后反而不对，不知道为何
			{
				if(G[a][b]=='#'&&t.w>0)//如果是敌人并且还有查克拉
				{
					q.push(node(a, b, t.w - 1, t.t + 1));
					W[a][b] = t.w - 1;//更新走到这里时剩余的最大查克拉
				}
				else if (G[a][b] == '*' || G[a][b] == '+')
				{
					q.push(node(a, b, t.w, t.t + 1));
					W[a][b] = t.w ;
				}
			}
		}
		q.pop();
	}
}
int main()
{
	cin >> M >> N >> T;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == '@')
			{
				mr = i; mc = j;
			}
		}
	memset(W, -1, sizeof(W));//以后数组赋值还是用memset比较保险
	bfs();
	if (ans != 1 << 30)
		cout << ans;
	else
		cout << -1;
	system("pause");
	return 0;
}