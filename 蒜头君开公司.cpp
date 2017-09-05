#include <iostream>
#include <algorithm>
#define MXN 10
using namespace std;
int N;
int task[MXN][MXN];
int arrange[MXN];//第i个任务让arrange[i]号员工完成
int Min = 1<<30;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> task[i][j];

	for (int i = 0; i < N; i++)
		arrange[i] = i;
	do
	{
		int total = 0;
		for (int i = 0; i < N; i++)
			total += task[i][arrange[i]];
		Min = min(total, Min);
	} while (next_permutation(arrange, arrange + N));
	cout << Min;
	system("pause");
	return 0;
}