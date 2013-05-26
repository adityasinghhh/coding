#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void print(vector<string> data[])
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 2; j++)
			cout << data[i][j] << ' ';
		cout << endl;
	}
}

int main()
{
	string data[3][2] = { {"cab","hello"}, {"cba","world"}, {"abc","haha"}};
	vector< string > v[3] =
	{vector< string >(data[0], data[0] + 2),
		vector< string >(data[1], data[1] + 2),
		vector< string >(data[2], data[2] + 2)};
	print(v);
	cout << endl;
	sort(v, v + 3);
	print(v);

	return 0;
}
