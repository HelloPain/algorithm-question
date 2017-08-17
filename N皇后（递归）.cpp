#include <iostream>
using namespace std;
int N;
int pos[100];//i��ʾ��,p[i]��ʾ��

void Nqueen(int k)//���õ�k�еĻʺ�
{
	if (k == N)
	{
		for (int i = 0; i < N; i++)
			printf("%d%c", pos[i]+1, i== N - 1 ? '\n' : ' ');
		return;
	}
	for (int cow = 0; cow < N; cow++)//����ÿһ���еĿ�����
	{
		int has = 0;
		for (; has < k; has++)//�����Ƿ��ͻ,has����
		{
			if (pos[has] == cow || abs(k - has) == abs(cow-pos[has]))
				break;
		}
		if (has == k)//û�г�ͻ
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