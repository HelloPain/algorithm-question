#include <iostream>
using namespace std;
//��ans[n]ans[n-1]ans[n-2]�Ĺ�ϵ��ans[n]=ans[n-1]+ans[n-2]*2
//��һ��͵�n-1����ɫ��һ�����n����һ�ֿ��ܣ���ʱans[n]=ans[n-1]
//��һ��͵�n-1����ɫһ�����n�������ֿ���,����ע���n-2��͵�һ����ɫһ����һ������ʱans[n]=ans[n-2]*2
int n;
long long ans[55];
void dp()
{
	ans[1] = 3;
	ans[2] = 6;
	ans[3] = 6;
	for (int i = 4; i <= n; i++)
		ans[i] = ans[i - 1] + ans[i - 2] * 2;
	cout << ans[n];
}
int main()
{
	cin >> n;
	dp();
	system("pause");
	return 0;
}