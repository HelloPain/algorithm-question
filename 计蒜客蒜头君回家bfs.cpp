#include <iostream>
#include <queue>
#define MAXN 2005
using namespace std;
char map[MAXN][MAXN];
int vis[2][MAXN][MAXN];//�õ�һ��ά�ȱ�ʾ�з���Կ��
//��Ϊע����Կ�׵���ĳ�����û��Կ�״ﵽĳ��������ȫ��ͬ��״̬��
//�����ֵĻ��������Կ��֮����Χ�����߹���·��֮ǰû��Կ�׵�ʱ���ǵģ�
int n, m;
typedef struct node
{
	int x, y, p, t;//p��ʾ�ѻ����Կ��
	node(int a, int b, int c, int d) :x(a), y(b), p(c), t(d) {};
}node;
queue<node> q;
int sx, sy;
int dir[] = { 0,1,0,-1,1,0,-1,0 };

void bfs()
{
	q.push(node(sx, sy, 0, 0));
	vis[0][sx][sy] = 1;
	while (!q.empty())
	{
		node h = q.front();
		if (map[h.x][h.y] == 'T'&&h.p==1)
		{
			cout << h.t; return;
		}
		for (int i = 0; i < 8; i += 2)
		{
			int a = h.x + dir[i]; int b = h.y + dir[i + 1];
			int v = 0;
			if (h.p)
				v = vis[1][a][b];
			else
				v = vis[0][a][b];
			if (a >= 0 && a < n&&b >= 0 && b < m && !v&&map[a][b] != '#')
			{
				node p(a, b, 0, h.t + 1);
				if (map[a][b] == 'P')
					p.p = 1;
			     if (h.p)
					p.p = 1;
				q.push(p);
				vis[p.p][a][b] = 1;
			}
		}
		q.pop();
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> map[i];
		for(int j=0;j<m;j++)
			if (map[i][j] == 'S')
			{
				sx = i; sy = j;
			}
	}
	memset(vis, 0, sizeof(vis));
	bfs();
	system("pause");
	return 0;
}