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
void print(int x)//�ݹ����
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
	while (head < tail)//���б���
	{
		x = list[head].r;
		y = list[head].c;
		if (x == 4 && y == 4)
		{
			print(head); return;
		}
		for (int i = 0; i < 8; i += 2)//���������ߵĵ�
		{
			xx = x + dir[i]; yy = y + dir[i + 1];
			if ( judge(xx, yy) && !maze[xx][yy])
			{
				maze[xx][yy] = -1;//���Ϊ�߹�
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
	list[0].f = -1;//��-1Ϊ������յ�
	while (head < tail)//�����в�Ϊ��
	{
		for (int i = 0; i < 8; i += 2)//��չ�ӽڵ�
		{
			if (list[head].r == 4 && list[head].c == 4)
			{
				print(head); return;
			}
			int a = list[head].r + dir[i];
			int b = list[head].c + dir[i + 1];		
			if (judge(a, b) && !maze[a][b])//���û�з��ʹ����ҿ����ߵ�
			{
				maze[a][b] = -1;
				list[tail].r = a; list[tail].c = b; list[tail].f = head;
				tail++;
			}
		}
		head++;//��չ����,��Ԫ�س�����
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