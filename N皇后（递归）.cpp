#include <iostream>
using namespace std;
int N;
int pos[100];//i表示行,p[i]表示列

void Nqueen(int k)//放置第k行的皇后
{
	if (k == N)
	{
		for (int i = 0; i < N; i++)
			printf("%d%c", pos[i]+1, i== N - 1 ? '\n' : ' ');
		return;
	}
	for (int cow = 0; cow < N; cow++)//遍历每一种列的可能性
	{
		int has = 0;
		for (; has < k; has++)//检验是否冲突,has是行
		{
			if (pos[has] == cow || abs(k - has) == abs(cow-pos[has]))
				break;
		}
		if (has == k)//没有冲突
		{
			pos[k] = cow;
			Nqueen(k + 1);
		}
	}
}
int main()
{
	cin >> N;
	Nqueen(0);
	system("pause");
	return 0;
}