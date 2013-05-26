#include <iostream>
#include <algorithm>
#include <iterator>

#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string>

#include <functional>
#include <utility>
#include <fstream>
#include <iosfwd>
#include <sstream>
#include <iomanip>

#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <complex>
#include <numeric>

using namespace std;

#define DEBUG                            1
#define Bug(X)                           if(DEBUG) cout<<#X<<" = "<<X<<endl
#define SYS                              system("pause")
#define VAR(x,a)                         __typeof(a) x(a)
#define FORD(i,a,b)                      for(int i = (int)a,_b = (int)b;i>=(_b);--i)
#define FOREACH(it,v)                    for(VAR(it,(v).begin());it!=(v).end();++it)
#define FOR(i,a,b)                       for(int i=(int)(a),_b = (int)b;i<(int)(_b);++i)
#define REP(i,n)                         FOR(i,0,n)
#define REPD(i,n)                        FORD(i,n,0)
#define PB                               push_back
#define PF                               push_front
#define MP                               make_pair
#define SZ                               size()
#define ALL(X)                           X.begin(),X.end()
#define RALL(X)                          X.rbegin(),X.rend()
#define Clear(X)                         memset(X,0,sizeof(X))
#define EPS                              1e-7
#define INF                              100000000
#define INFLL                            10000000000000000LL

typedef vector< int > VI; typedef vector< string > VS; typedef long long LL;
typedef vector<VI> VVI; typedef pair< int,int > PII; typedef vector<VS> VVS;
typedef unsigned long long ULL;  typedef vector<PII> VPII; typedef vector<LL> VLL;

int rInt(){int nT = -1; scanf( "%d", &nT ); return nT; }
int strToInt( string &S ) { int nT = 0; REP( i, S.SZ ) nT = nT * 10 + ( S[i] - '0' ); return nT;}
string intToStr(int N){string S;do{S.PB(N%10+'0');N/=10;}while(N);reverse(ALL(S));return S;}
string vIntToStr(VI V){string S;REP(i,V.SZ) S.PB(V[i]+'0');return S;}
string rStr(){char nStr[1024]; scanf( "%s", nStr ); return nStr; }
VI strToVInt(string &S){VI V;REP(i,S.SZ) V.PB(S[i]-'0');return V;}
LL rLL(){LL nT = -1; cin>>nT; return nT; }
template<class T> ostream& operator << (ostream &O,vector<T> &V) { O<<"{"; REP(i,V.SZ-1) O<<V[i]<<", ";O<<V[V.SZ-1];O<<"}";return O;}

class BigNumber
{
	private: vector< int > number;
	public: BigNumber() {
			number.PB( 1 );
		}
	public: BigNumber( string inStr ) {
			number.resize( inStr.SZ );
			reverse( ALL( inStr ) );
			for( int i = 0; i < inStr.SZ; ++i )
				number[i] = inStr[i] - '0';
		}
	public: int size() {
			return ( int ) number.SZ;
		}
	public: string toString() {
			string retStr;
			for( int i = 0; i < number.SZ; ++i )
				retStr.PB( number[i] + '0' );
			reverse( ALL( retStr ) );
			return retStr;
		}	
	public: void displayBigNumber()  {
			int lastIdx = number.SZ - 1;
			for( int i = lastIdx; i >= 0; --i )
				printf( "%d", number[i] );
		}
	public: void addInt( int inNumber ) {
			number.resize( number.SZ + 2, 0 );
			number[0] += inNumber;
			for( int i = 0; i + 1 < number.SZ; ++i ) {
				number[i+1] += number[i]/10;
				number[i] %= 10;
			}
			int lastIdx = number.SZ - 1;
			while( lastIdx >= 1 && number[ lastIdx ] == 0 )
				--lastIdx;
			number.resize( lastIdx + 1 );
		}
	public: void multiplyInt( int inNumber ) {
			number.resize( number.SZ + 10, 0 );
			for( int i = 0; i < number.SZ; ++i )
				number[i] *= inNumber;
			for( int i = 0; i + 1 < number.SZ; ++i ) {
				number[i+1] += number[i]/10;
				number[i] %= 10;
			}
			int lastIdx = number.SZ - 1;
			while( lastIdx >= 1 && number[ lastIdx ] == 0 )
				--lastIdx;
			number.resize( lastIdx + 1 );
		}
	public: void addBigNumber( BigNumber B ) {
			int maxSize = max( B.SZ, ( int ) number.SZ ) + 2;
			number.resize( maxSize, 0 );
			B.number.resize( maxSize, 0 );
			for( int i = 0; i < maxSize; ++i )
				number[i] += B.number[i];
			for( int i = 0; i + 1 < number.SZ; ++i ) {
				number[i+1] += number[i]/10;
				number[i] %= 10;
			}
			int lastIdx = number.SZ - 1;
			while( lastIdx >= 1 && number[ lastIdx ] == 0 )
				--lastIdx;
			number.resize( lastIdx + 1 );
		}
	public: void multiplyBigNumber( BigNumber B ) {
			vector< int > tempNumber;
			tempNumber.resize( B.SZ + number.SZ + 10, 0 );
			for( int i = 0; i < B.SZ; ++i )
				for( int j = 0; j < number.SZ; ++j )
					tempNumber[i+j] += B.number[i]*number[j];
			for( int i = 0; i + 1 < tempNumber.SZ; ++i ) {
				tempNumber[i+1] += tempNumber[i]/10;
				tempNumber[i] %= 10;
			}
			int lastIdx = tempNumber.SZ - 1;
			while( lastIdx >= 1 && tempNumber[ lastIdx ] == 0 )
				lastIdx--;
			tempNumber.resize( lastIdx + 1 );
			number = tempNumber;
		}
};

int main()
{
	int nTest = rInt();
	while( nTest-- ) {
		int N = rInt();
		BigNumber B( "2" );
		for( int i = 1; i <= N; ++i ) {
			B.multiplyInt( 2 * i - 1 );
		}
		cout << B.toString() << endl;
	}
	return 0;
}


