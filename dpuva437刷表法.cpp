#include <iostream>
#include <algorithm>
using namespace std;

struct block
{
	int x, y, z;
	void init(int a, int b, int c) { x = a; y = b; z = c; }
}node[200];
int d[200];
int T;
int ans = 0;
int cnt = 0;
int total = 0;
bool cmp(block a,block b)
{
	return a.x*a.y < b.x*b.y;
}
void dp()
{
	for (int i = 0; i < total; i++)
	{
		d[i] = node[i].z;
		for (int j = 0; j < i; j++)
		{
			if (node[i].x>node[j].x&&node[i].y>node[j].y)
			{
				d[i] = max(d[i], d[j] + node[i].z);
			}
		}
		if (d[i] > ans)
			ans = d[i];
	}
	cout << "Case" << ++cnt << ":" << ans << endl;
}

int main()
{
	while (cin >> T&&T)
	{
		int a, b, c;
		total = 0;
		for (int i = 0; i < T; i++)
		{
			cin >> a >> b >> c;
			node[total++].init(a, b, c);
			node[total++].init(a, c, b);
			node[total++].init(c, a, b);
			node[total++].init(b,a,c);
			node[total++].init(b,c, a);
			node[total++].init(c, b, a);
		}
		sort(node, node + total, cmp);
		memset(d, 0, sizeof(d));
		ans = 0;
		dp();
	}

	system("pause");
	return 0;
}