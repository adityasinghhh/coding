#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;



int main() {


	int a[] = {1,2,3,4,5,6,7,8,9};

	long long cnt = 0;
	do {
		int t1 = 0, t2 = 0, t3 = 0;
		for(int i = 0 ; i < 4; ++i) t1 += a[i];
		for(int i = 3;  i < 7; ++i) t2 += a[i];
		for(int i = 6;  i < 9; ++i) t3 += a[i]; t3 += a[0];

		if(t1 == t2 && t2 == t3) ++cnt;
	}while(next_permutation(a,a+9));

	cout << cnt << endl;


}
