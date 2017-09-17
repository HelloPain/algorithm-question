#include <iostream>
using namespace std;
//找ans[n]ans[n-1]ans[n-2]的关系：ans[n]=ans[n-1]+ans[n-2]*2
//第一块和第n-1块颜色不一样则第n块有一种可能，此时ans[n]=ans[n-1]
//第一块和第n-1块颜色一样则第n块有两种可能,并且注意第n-2块和第一块颜色一定不一样，此时ans[n]=ans[n-2]*2
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