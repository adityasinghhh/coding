#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class P8XCoinChangeAnother {
public:
	vector<long long> solve(int, long long, long long);
};

map<long long, long long> m;
map<long long, long long>::iterator it;
bool flag;
vector<long long> v;

void f(int n, long long cs, long long cc)
{
	printf("%d %lld %lld\n", n, cs, cc);
	
	if(n == 0) { if(cc == cs) { flag = true; v[n] = cc; } return; }

	for(int i = 0; ; ++i)
	{
		printf("I: %d\n", i);
		
		long long val = 1ll*i*(1<<n);

		if(cs-val < 0) { return; }

		f(n-1, cs-val, cc-i);

		if(flag) { v[n] = i; return; }
	}
	
	return;
}

vector<long long> P8XCoinChangeAnother::solve(int N, long long coins_sum, long long coins_count) {

	flag = false;

	for(int i=0; i<N; ++i) { v.push_back(0); }

	f(N-1, coins_sum, coins_count);

	if(!flag) { vector<long long> v1; return v1; }
	return v;
}

//Powered by [KawigiEdit] 2.0!
