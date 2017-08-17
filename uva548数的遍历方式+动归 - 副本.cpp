#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const int maxv = 10010;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;//总结点个数

bool read_list(int* a)
{
	string line;
	if (!getline(cin, line))return false;
	stringstream ss(line);
	n = 0;
	int x;
	while (ss >> x)a[n++] = x;
	return n > 0;
}

int build(int L1, int R1, int L2, int R2)
{
	if (L1 > R1)return 0;//空树
	int root = post_order[R2];//后序排序的最后一个节点是根节点
	int p = L1;
	while (in_order[p] != root)p++;
	int cnt = p - L1;//左子树的节点个数
	lch[root] = build(L1, p - 1, L2, L2 + cnt - 1);
	rch[root] = build(p + 1, R1, L2 + cnt, R2 - 1);
	return root;
}

int best, best_sum;
void dfs(int u, int sum)
{
	sum += u;
	if (!lch[u] && !rch[u])
	{
		if (sum < best_sum || (sum == best_sum&&u < best))
		{
			best = u; best_sum = sum;
		}
	}
	if (lch[u])dfs(lch[u], sum);
	if (rch[u])dfs(rch[u], sum);
}
int main()
{
	while (read_list(in_order))
	{
		read_list(post_order);
		build(0, n - 1, 0, n - 1);
		best_sum = 1 << 12;
		dfs(post_order[n - 1], 0);
		cout << best << '\n';
	 }
	system("pause");
	return 0;
}