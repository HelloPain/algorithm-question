#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a[] = { 1,2,3 };
	do
	{
		printf("%d %d %d\n", a[0], a[1], a[2]);
	} while (std::next_permutation(a, a + 3));
	system("pause");
	return 0;
}