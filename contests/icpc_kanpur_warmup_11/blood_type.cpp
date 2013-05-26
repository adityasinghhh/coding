
#include<algorithm>
#include<assert.h>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=a;i>b;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define LL long long int
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b

int main()
{
	int zz, i;

	string A, B, C;
	char a1, a2, b1, b2;
	int s1, s2;
	
	for(zz=1; ; ++zz)
	{
		cin>>A; cin>>B; cin>>C;

		if(A == "E" && B == "N" && C == "D")
			return 0;

		printf("Case %d: ", zz);
			
		if(A == "O+")  { a1 = 'O'; a2 = 'O'; s1 = 1;  } else
		if(A == "O-")  { a1 = 'O'; a2 = 'O'; s1 = -1; } else
		if(A == "AB+") { a1 = 'A'; a2 = 'B'; s1 = 1;  } else
		if(A == "AB-") { a1 = 'A'; a2 = 'B'; s1 = -1; } else
		if(A == "A+")  { a1 = 'A'; a2 = 'O'; s1 = 1;  } else
		if(A == "A-")  { a1 = 'A'; a2 = 'O'; s1 = -1; } else
		if(A == "B+")  { a1 = 'B'; a2 = 'O'; s1 = 1;  } else
		if(A == "B-")  { a1 = 'B'; a2 = 'O'; s1 = -1; }

		if(B == "?")
		{
			if(C == "O+")  { b1 = 'O'; b2 = 'O'; s2 = 1;  } else
			if(C == "O-")  { b1 = 'O'; b2 = 'O'; s2 = -1; } else
			if(C == "AB+") { b1 = 'A'; b2 = 'B'; s2 = 1;  } else
			if(C == "AB-") { b1 = 'A'; b2 = 'B'; s2 = -1; } else
			if(C == "A+")  { b1 = 'A'; b2 = 'O'; s2 = 1;  } else
			if(C == "A-")  { b1 = 'A'; b2 = 'O'; s2 = -1; } else
			if(C == "B+")  { b1 = 'B'; b2 = 'O'; s2 = 1;  } else
			if(C == "B-")  { b1 = 'B'; b2 = 'O'; s2 = -1; }

			set<string> child;
			set<string>::iterator it;

			if(a1 == b1)
			{
				if(b2 == 'A') { child.insert("AB+"); child.insert("A+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("A-"); } } else
				if(b2 == 'B') { child.insert("AB+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("B-"); } } else
				if(b2 == 'O') { child.insert("A+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("O+"); child.insert("A-"); child.insert("B-"); child.insert("O-"); } } 
			}

			if(a2 == b1)
			{
				if(b2 == 'A') { child.insert("AB+"); child.insert("A+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("A-"); } } else
				if(b2 == 'B') { child.insert("AB+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("B-"); } } else
				if(b2 == 'O') { child.insert("A+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("O+"); child.insert("A-"); child.insert("B-"); child.insert("O-"); } } 
			}

			if(a1 == b2)
			{
				if(b1 == 'A') { child.insert("AB+"); child.insert("A+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("A-"); } } else
				if(b1 == 'B') { child.insert("AB+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("B-"); } } else
				if(b1 == 'O') { child.insert("A+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("O+"); child.insert("A-"); child.insert("B-"); child.insert("O-"); } } 
			}

			if(a2 == b2)
			{
				if(b1 == 'A') { child.insert("AB+"); child.insert("A+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("A-"); } } else
				if(b1 == 'B') { child.insert("AB+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("AB-"); child.insert("B-"); } } else
				if(b1 == 'O') { child.insert("A+"); child.insert("B+"); if(s1 > 0 && s2 < 0) { child.insert("O+"); child.insert("A-"); child.insert("B-"); child.insert("O-"); } } 
			}

			printf("%s ", A.c_str());

			if(child.size() == 0) printf("IMPOSSIBLE");
			else
			{
				if(child.size() != 1) printf("{");
				for(i=0, it = child.begin(); it != child.end(); ++it, ++i) { cout<<*it; if(i != child.size()-1) printf(", "); }
				if(child.size() != 1) printf("}");
			}

			printf(" %s\n", C.c_str());
		}
		else
		{
			if(B == "O+")  { b1 = 'O'; b2 = 'O'; s2 = 1;  } else
			if(B == "O-")  { b1 = 'O'; b2 = 'O'; s2 = -1; } else
			if(B == "AB+") { b1 = 'A'; b2 = 'B'; s2 = 1;  } else
			if(B == "AB-") { b1 = 'A'; b2 = 'B'; s2 = -1; } else
			if(B == "A+")  { b1 = 'A'; b2 = 'O'; s2 = 1;  } else
			if(B == "A-")  { b1 = 'A'; b2 = 'O'; s2 = -1; } else
			if(B == "B+")  { b1 = 'B'; b2 = 'O'; s2 = 1;  } else
			if(B == "B-")  { b1 = 'B'; b2 = 'O'; s2 = -1; }

			set<string> child;
			set<string>::iterator it;

			child.insert("O+"); child.insert("O-");	child.insert("A+"); child.insert("A-");	child.insert("B+"); child.insert("B-");	child.insert("AB+"); child.insert("AB-");

			if(s1 < 0 && s2 < 0) { child.erase("O+"); child.erase("A+"); child.erase("B+"); child.erase("AB+"); }

			if((a1 == 'O' && b1 == 'O') || (a1 == 'O' && b2 == 'O') || (a2 == 'O' && b1 == 'O') || (a2 == 'O' && b2 == 'O')) {} else { child.erase("O+"); child.erase("O-"); }
			
			if((a1 == 'A' && b1 == 'B') || (a1 == 'A' && b2 == 'B') || (a2 == 'A' && b1 == 'B') || (a2 == 'A' && b2 == 'B') || (a1 == 'B' && b1 == 'A') || (a1 == 'B' && b2 == 'A') || (a2 == 'B' && b1 == 'A') || (a2 == 'B' && b2 == 'A')) {} else { child.erase("AB+"); child.erase("AB-"); }
			
			if((a1 == 'A' && b1 == 'O') || (a1 == 'A' && b2 == 'O') || (a2 == 'A' && b1 == 'O') || (a2 == 'A' && b2 == 'O') || (a1 == 'O' && b1 == 'A') || (a2 == 'O' && b1 == 'A') || (a2 == 'O' && b1 == 'A') || (a2 == 'O' && b2 == 'A') || (a1 == 'A' && b1 == 'A') || (a1 == 'A' && b2 == 'A') || (a2 == 'A' && b1 == 'A') || (a2 == 'A' && b2 == 'A')) {} else { child.erase("A+"); child.erase("A-"); }
			
			if((a1 == 'B' && b1 == 'O') || (a1 == 'B' && b2 == 'O') || (a2 == 'B' && b1 == 'O') || (a2 == 'B' && b2 == 'O') || (a1 == 'O' && b1 == 'B') || (a2 == 'O' && b1 == 'B') || (a2 == 'O' && b1 == 'B') || (a2 == 'O' && b2 == 'B') || (a1 == 'B' && b1 == 'B') || (a1 == 'B' && b2 == 'B') || (a2 == 'B' && b1 == 'B') || (a2 == 'B' && b2 == 'B')) {} else { child.erase("B+"); child.erase("B-"); }

			printf("%s %s ", A.c_str(), B.c_str());
			if(child.size() == 0) printf("IMPOSSIBLE\n");
			else
			{
				if(child.size() != 1) printf("{");
				for(i=0, it = child.begin(); it != child.end(); ++it, ++i) { cout<<*it; if(i != child.size()-1) printf(", "); }
				if(child.size() != 1) printf("}");
				printf("\n");
			}
		}
	}
}
