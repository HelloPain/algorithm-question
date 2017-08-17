#include<cstdio>
#include<cstring>
#define N 100
int g[N + 1][N + 1], u, v, n, m, stack[N + 1], vis[N + 1], pos = 0;
void push(int x) {
	stack[pos++] = x;
}
int pop() {
	return stack[--pos];
}
void dfs(int u) {
	vis[u] = -1;//visting
	for (int i = 1; i <= n; i++)if (g[u][i] && !vis[i])
		dfs(i);
	push(u); vis[u] = 1;//visted
}
int maina() {
	while (scanf("%d%d", &n, &m) == 2 && (m || n)) {//这里是m或n，与的话会wa，我离散数学要去面壁 
		while (m--) {
			scanf("%d%d", &u, &v);
			g[u][v] = 1;
		}
		memset(vis, 0, sizeof(vis));//initialization
		for (int i = 1; i <= n; i++)//topological sort
			if (!vis[i])dfs(i);
		while (pos) {//print result
			printf("%d", pop());
			printf("%c", pos>0 ? ' ' : '\n');//三目运算符真的很好用
		}
	}
	return 0;
}