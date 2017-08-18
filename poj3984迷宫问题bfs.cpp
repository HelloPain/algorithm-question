//poj3984 bfs
#include <iostream>
using namespace std;
int maze[5][5];
int head = 0;
int tail = 1;
struct node
{
	int r, c, f;
}list[50];

int dir[8] = { 1,0,-1,0,0,1,0,-1 };
void print(int x)//递归输出
{
	if (list[x].f != -1)
	{
		print(list[x].f);
		printf("(%d,%d)\n", list[x].r, list[x].c);
	}
}
bool judge(int x, int y)
{
	return x >= 0 && x < 5 && y >= 0 && y < 5;
}
/*
void bfs()
{
	list[0].r = list[0].c = 0;
	list[0].f = -1;
	int x, xx, y, yy;
	while (head < tail)//当列表不空
	{
		x = list[head].r;
		y = list[head].c;
		if (x == 4 && y == 4)
		{
			print(head); return;
		}
		for (int i = 0; i < 8; i += 2)//遍历可以走的点
		{
			xx = x + dir[i]; yy = y + dir[i + 1];
			if ( judge(xx, yy) && !maze[xx][yy])
			{
				maze[xx][yy] = -1;//标记为走过
				list[tail].r = xx;
				list[tail].c = yy;
				list[tail].f = head;
				tail++;
			}
		}
		head++;
	}
}*/
void bfs()
{
	list[0].c = list[0].r = 0;
	list[0].f = -1;//以-1为输出的终点
	while (head < tail)//当队列不为空
	{
		for (int i = 0; i < 8; i += 2)//扩展子节点
		{
			if (list[head].r == 4 && list[head].c == 4)
			{
				print(head); return;
			}
			int a = list[head].r + dir[i];
			int b = list[head].c + dir[i + 1];		
			if (judge(a, b) && !maze[a][b])//如果没有访问过并且可以走到
			{
				maze[a][b] = -1;
				list[tail].r = a; list[tail].c = b; list[tail].f = head;
				tail++;
			}
		}
		head++;//扩展结束,该元素出队列
	}
}
int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> maze[i][j];
	bfs();
	system("pause");
	return 0;
}