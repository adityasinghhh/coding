
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
#define FOR(i,a,b) for(i=a;i<b;++i)
#define FORD(i,a,b) for(i=b-1;i>=a;--i)
#define REP(i,b) for(i=0;i<b;++i)
#define REPD(i,b) for(i=b-1;i>=0;--i)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)
#define FILL(a,b) memset(a,b,sizeof a)
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
#define ABS(a) (a)<0?-(a):(a)
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 

class Point 
{
	public:
		Point(float a = 1.0, float b = 1.0, float c = 1.0);
		~Point();

		float getX();
		float getY();
		float getZ();
		
		void setX(float);
		void setY(float);
		void setZ(float);

		void setXYZ(float, float, float);

		void getXYZ(float&, float&, float&);

		Point operator=(Point &P);

	private:
		float x, y, z;

	protected:
};

Point::Point(float a, float b, float c)
{
	cout << "We're in the constructor with arguments and " << (int) this << endl;
	this->x = a; y = b; this->z = c;
}

Point::~Point()
{
	cout << "We're in the destructor with arguments: " << x << ", " << y << ", " << z << " and " << (int)this << endl;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}

float Point::getZ()
{
	return z;
}

void Point::setX(float X)
{
	x = X;
}

void Point::setY(float Y)
{
	y = Y;
}

void Point::setZ(float Z)
{
	z = Z;
}

void Point::setXYZ(float X, float Y, float Z)
{
	setX(X); setY(Y); setZ(Z);
}

void Point::getXYZ(float &X, float &Y, float &Z)
{
	X = getX(); Y = getY(); Z = getZ();
}

ostream &operator<<(ostream &stream, Point &p)
{
	stream << p.getX() << " " << p.getY() << " " << p.getZ(); 

	return stream;
}

istream &operator>>(istream &stream, Point &p)
{
	int X, Y, Z;
	stream >> X >> Y >> Z;
	p.setXYZ(X, Y, Z);

	return stream;
}

Point Point::operator=(Point &p)
{
	setX(p.getX());
	setY(p.getY());
	setZ(p.getZ());

	return *this;
}

int main()
{
	Point p(1, 2, 3), q;

	cout << "X is: " << p.getX() << endl;
	cout << "Y is: " << p.getY() << endl;
	cout << "Z is: " << p.getZ() << endl;

	p.setX(1); p.setY(4); p.setZ(9);

	cout << "X is: " << p.getX() << endl;
	cout << "Y is: " << p.getY() << endl;
	cout << "Z is: " << p.getZ() << endl;

	p.setXYZ(1, 16, 81);

	cout << "X is: " << p.getX() << endl;
	cout << "Y is: " << p.getY() << endl;
	cout << "Z is: " << p.getZ() << endl;

	float x, y, z;

	p.getXYZ(x, y, z);

	cout << "X is: " << x << endl;
	cout << "Y is: " << y << endl;
	cout << "Z is: " << z << endl;

	operator << (cout, p) << endl;
	cout << p << endl;

	cin >> p;
	cout << p << endl;

	q = p;
	cout << q << endl;

	return 0;
}
