#include<cstdio>
#include<vector>
using namespace std;
int main()
{
	vector<int> v1, v2;
	
	v1.push_back(0);
	v1.push_back(2);
	v1.push_back(4);
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(3);

	if(v1 < v2)
		printf("v1\n");
	else
		printf("v2\n");

	return 0;
}
