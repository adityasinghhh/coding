
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

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PI;

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define lc(i) (i<<1)
#define rc(i) ((i<<1)+1)
#define iscan(n) scanf("%d",&n)
#define cscan(n) scanf("%c",&n)
#define llscan(n) scanf("%lld",&n)
#define lfscan(n) scanf("%lf",&n)
#define sscan(n) scanf("%s",n)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORD(i,a,b) for(int i=b-1;i>=a;--i)
#define REP(i,b) for(int i=0;i<b;++i)
#define REPD(i,b) for(int i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)<0?-(a):(a))
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

int main()
{
	char inp[100000];
	
	VI order_id, deal_id;
	vector<string> email, streetAddress, city, state, zipCode, creditCard;
	map<int, int> index;

	int N = SI;
	REP(i,N)
	{
		scanf(" %[^\n]", inp);

		int j = 0;

		int oid = 0; while(inp[j] != ',') { oid = oid*10 + (inp[j]-'0'); ++j; }
		order_id.PB(oid);
		index[oid] = i;
		
		++j;

		int did = 0; while(inp[j] != ',') { did = did*10 + (inp[j]-'0'); ++j; }
		deal_id.PB(did);

		++j; 

		bool flag = false, flag1 = false; 
		string temp = ""; 
		while(inp[j] != ',') 
		{
			if(inp[j] >= 'A' && inp[j] <= 'Z') { inp[j] += 32; }
			if(inp[j] == '+') { flag = true; } 
			if(inp[j] == '@') { flag = false; flag1 = true; } 
			if(!flag) { if(flag1 || inp[j] != '.') { temp += inp[j]; } }
			++j; 
		}
		email.PB(temp);

		++j;

		temp = ""; 
		while(inp[j] != ',') 
		{ 
			if(inp[j] >= 'A' && inp[j] <= 'Z') { inp[j] += 32; }
			temp += inp[j]; ++j; 
		}

		int l = temp.length();
		string temp1 = "";
		REP(k,l) 
		{ 
			if(l-k > 5 && temp[k] == 's' && temp[k+1] == 't' && temp[k+2] == 'r' && temp[k+3] == 'e' && temp[k+4] == 'e' && temp[k+5] == 't')
			{
				temp1 += "st.";
				k += 5;
			}
			else if(l-k > 3 && temp[k] == 'r' && temp[k+1] == 'o' && temp[k+2] == 'a' && temp[k+3] == 'd')
			{
				temp1 += "rd.";
				k += 3;
			}
			else 
			{
				temp1 += temp[k];
			}
		}
		streetAddress.PB(temp1);

		++j;

		temp = ""; 
		while(inp[j] != ',') 
		{ 
			if(inp[j] >= 'A' && inp[j] <= 'Z') { inp[j] += 32; }
			temp += inp[j]; ++j; 
		}
		city.PB(temp);
		
		++j;

		temp = ""; 
		while(inp[j] != ',') 
		{ 
			if(inp[j] >= 'A' && inp[j] <= 'Z') { inp[j] += 32; }
			temp += inp[j]; ++j; 
		}

		l = temp.length();
		temp1 = "";
		REP(k,l) 
		{ 
			if(l-k > 9 && temp[k] == 'c' && temp[k+1] == 'a' && temp[k+2] == 'l' && temp[k+3] == 'i' && temp[k+4] == 'f' && temp[k+5] == 'o' && temp[k+6] == 'r' && temp[k+7] == 'n' && temp[k+8] == 'i' && temp[k+9] == 'a')
			{
				temp1 += "ca";
				k += 9;
			} 
			else if(l-k > 7 && temp[k] == 'i' && temp[k+1] == 'l' && temp[k+2] == 'l' && temp[k+3] == 'i' && temp[k+4] == 'n' && temp[k+5] == 'o' && temp[k+6] == 'i' && temp[k+7] == 's')
			{
				temp1 += "il";
				k += 7;
			}
			else if(l-k > 7 && temp[k] == 'n' && temp[k+1] == 'e' && temp[k+2] == 'w' && temp[k+3] == ' ' && temp[k+4] == 'y' && temp[k+5] == 'o' && temp[k+6] == 'r' && temp[k+7] == 'k')
			{
				temp1 += "ny";
				k += 7;
			}
			else
			{
				temp1 += temp[k];
			}
		}			
		state.PB(temp1);

		++j;

		temp = ""; while(inp[j] != ',') { temp += inp[j]; ++j; }
		zipCode.PB(temp);
		
		++j;

		temp = ""; while(inp[j] != 0) { temp += inp[j]; ++j; }
		creditCard.PB(temp);
	}

	int sz = deal_id.size();

	map<pair<int, string>, VI> type1, type2;
	map<pair<int, string>, VI>::iterator it;
	pair<int, string> p;

	VI fraudulent;

	REP(i,sz)
	{
		p = MP(deal_id[i], email[i]);

		it = type1.find(p);
		if(it != type1.end())
		{
			bool flag = false;
			int sz1 = type1[p].size();
			REP(j,sz1)
			{
				if(creditCard[type1[p][j]] != creditCard[i])
				{
					fraudulent.PB(type1[p][j]);
					flag = true;
				}
			}
			if(flag) { fraudulent.PB(i); }
		}
		else { VI temp; type1[p] = temp; }
		type1[p].PB(i);

		p = MP(deal_id[i], streetAddress[i]+city[i]+state[i]+zipCode[i]);
		it = type2.find(p);
		if(it != type2.end())
		{
			bool flag = false;
			int sz1 = type2[p].size();
			REP(j,sz1)
			{
				if(creditCard[type2[p][j]] != creditCard[i])
				{
					fraudulent.PB(type2[p][j]);
					flag = true;
				}
			}
			if(flag) { fraudulent.PB(i); }
		}
		else { VI temp; type2[p] = temp; }
		type2[p].PB(i);
	}

	SORT(fraudulent);
	sz = fraudulent.size();

	if(sz)
	{
		VI print; print.PB(order_id[fraudulent[0]]);
		FOR(i,1,sz) 
		{
			if(fraudulent[i] != fraudulent[i-1])
			{
				print.PB(order_id[fraudulent[i]]);
			}
		}

		sz = print.size();
		if(sz)
		{
			REP(i,sz)
			{
				printf("%d", print[i]);
				printf(i == sz-1 ? "\n" : ",");
			}
		}
	}

	return 0;
}
