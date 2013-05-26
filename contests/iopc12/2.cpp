
#include<algorithm>
#include<assert.h>
#include<bitset>
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
typedef vector<pair<int,int> > VPI;
typedef pair<double,double> PD;

#define LL long long int
#define SI ({int _x; scanf("%d",&_x); _x;})
#define SC ({char _x; scanf("%c",&_x); _x;})
#define SLL ({LL _x; scanf("%lld",&_x); _x;})
#define SLF ({double _x; scanf("%lf",&_x); _x;})
#define PI(x) printf("%d",&x)
#define PC(x) printf("%c",&x)
#define PLL(x) printf("%lld",&x)
#define PLF(x) printf("%lf",&x)
#define PS(x) printf("%s",&x)
#define PSP() printf(" ")
#define PSN() printf("\n")
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

template<class T> inline int size(const T&c) { return c.size(); }
 
typedef int coord;
 
struct Point {
	double x,y;
	Point() {}
	Point(double x,double y):x(x),y(y) {}
};
 
Point operator+(const Point &A,const Point&B) { return Point(A.x+B.x,A.y+B.y); }
Point operator-(const Point &A,const Point&B) { return Point(A.x-B.x,A.y-B.y); }
Point operator*(double c, const Point &A) { return Point(c*A.x,c*A.y); }
double operator^(const Point&A,const Point&B) { return A.x*B.y-A.y*B.x; }
double operator*(const Point&A,const Point&B) { return A.x*B.x+A.y*B.y; }
double len2(const Point&A) { return A*A; }
double len(const Point&A) { return sqrt((double)len2(A)); }

double distance(const Point&A, const Point&B) { Point X = A-B; return len(X); }

double angle(const Point&A, const Point&B) { return acos((double)(A*B)/len(A)/len(B)); }

double area(const Point&A, const Point&B, const Point&C) { return fabs((double)((A-C)^(B-C))/2.0); }

double linePointDistance(const Point&A, const Point&B, const Point&C, bool isSegment)
{
	Point X = B-A; Point Y = C-A;
	double dist = (X^Y)/sqrt((double)len2(A-B));
	
	if(isSegment)
	{
		X = C-B; Y = B-A;
		double dot1 = X*Y;
		if(dot1 > 0.0) { return sqrt((double)len2(B-C)); }
		X = C-A; Y = A-B;
		double dot2 = (C-A)*(A-B);
		if(dot2 > 0.0) { return sqrt((double)len2(A-C)); }
	}

	return fabs(dist);
}

double PolygonArea(vector<Point> points)
{
	double Area = 0.0;

	FOR(i,1,points.size()-1) { Area += area(points[0], points[i], points[i+1]); }

	return Area;
}

PD intersectionPoint(const Point&A, const Point&B, double A1, double B1, double C1, double A2, double B2, double C2, bool isSegment = false)
{
	double det = A1*B2 - A2*B1;

	if(det == 0.0) { return MP(INT_MAX, INT_MAX); }
	else
	{
		double x = (B2*C1 - B1*C2)/det;
		double y = (A1*C2 - A2*C1)/det;

		if(isSegment) 
		{
			double minix = MIN(A.x, B.x);	double maxix = MAX(A.x, B.x);
			double miniy = MIN(A.y, B.y);	double maxiy = MAX(A.y, B.y);

			if(minix <= x && x <= maxix && miniy <= y && y <= maxiy) { return MP(x,y); }
			else { return MP(INT_MAX, INT_MAX); }
		}
		
		return MP(x,y);		
	}
}

/* Returns the point of intersection for the lines formed by A and B and C and D */
PD lineLineIntersection(const Point&A, const Point&B, const Point&C, const Point&D, bool isSegment = false)
{
	double A1 = B.y-A.y;	double B1 = A.x-B.x;	double C1 = A1*A.x+B1*A.y;
	double A2 = D.y-C.y;	double B2 = C.x-D.x;	double C2 = A1*C.x+B1*C.y;

	return intersectionPoint(A, B, A1, B1, C1, A2, B2, C2, isSegment);
}

/* Returns the coordinates of the centre of the circle */
PD findCircle(const Point&A, const Point&B, const Point&C)
{
	double A1, A2, B1, B2, C1, C2, midx, midy;

	A1 = B.y-A.y;	B1 = A.x-B.x;	C1 = A1*A.x+B1*A.y;
	midx = (double)(A.x+B.x)/2.0;   midy = (double)(A.y+B.y)/2.0;
	A2 = -B1; 	B2 = A1;	C2 = A2*midx+B2*midy;

	PD p1 = intersectionPoint(A, B, A1, B1, C1, A2, B2, C2);

	A1 = C.y-B.y;	B1 = B.x-C.x;	C1 = A1*B.x+B1*B.y;
	midx = (double)(B.x+C.x)/2.0;	midy = (double)(B.y+C.y)/2.0;
	A2 = -B1;	B2 = A1;	C2 = A2*midx+B2*midy;

	PD p2 = intersectionPoint(B, C, A1, B1, C1, A2, B2, C2);

	double precision = 0.000001;
	if(fabs(p1.first-p2.first) > precision && fabs(p1.second-p2.second) > precision) { return p1; }
	
	return MP(INT_MAX, INT_MAX);		
}

PD pointReflectionOnALine(const Point&A, const Point&B, const Point&C)
{
	double A1, A2, B1, B2, C1, C2;
	
	A1 = B.y-A.y;	B1 = A.x-B.x;	C1 = A1*A.x+B1*A.y;
	A2 = -B1; 	B2 = A1;	C2 = A2*C.x+B2*C.y;

	PD p = intersectionPoint(A, B, A1, B1, C1, A2, B2, C2);

	return MP(p.first - (C.x - p.first), p.second - (C.y - p.second));
}

/* Rotate A around B by theta degree*/
PD pointRotationAroundAPoint(const Point&A, const Point&B, double theta)
{
	double angle = M_PI*theta/180.0;

	Point C = A-B;
	double x = C.x*cos(angle) - C.y*sin(angle);
	double y = C.x*sin(angle) + C.y*cos(angle);

	x += B.x;	y += B.y;

	return MP(x, y);
}

bool operator<(const Point&a, const Point&b) {
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
 
double distance(double x1, double y1, double x2, double y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

double dist(PD p1, PD p2)
{
	return distance(p1.first, p1.second, p2.first, p2.second);
}

double E = 0.000001;
LL BASE = 100000007;

int main() 
{
	int T = SI;
	while(T--)
	{
		vector<PD > v;
		double x, y;
		x = SLF; y = SLF; v.PB(MP(x,y));
		x = SLF; y = SLF; v.PB(MP(x,y));
		x = SLF; y = SLF; v.PB(MP(x,y));
		x = SLF; y = SLF; v.PB(MP(x,y));

		vector<vector<double> > V;
		double maxi = -1.0;
		REP(i,4)
		{
			vector<double> temp; V.PB(temp);
			REP(j,4)
			{
				V[i].PB(dist(v[i], v[j]));
				maxi = MAX(maxi, V[i][j]);
			}
		}

		double cx, cy;
		bool flag = false;
		REP(i,4) 
		{
			FOR(j,i+1,4) 
			{
				if(dist(v[i], v[j]) == maxi) 
				{ 
					cx = (v[i].first+v[j].first)/2.0; 
					cy = (v[i].second+v[j].second)/2.0;  
					flag = true;
					break;
				}
			}
			if(flag) { break; }
		}

//		REP(i,4) { FOR(j,i+1,4) { printf("Distance between (%lf,%lf) and (%lf,%lf) is %lf\n", v[i].first, v[i].second, v[j].first, v[j].second, V[i][j]); } }

		Point C(cx, cy);
//		printf("Center point: (%lf,%lf)\n", cx, cy);
		vector<PD > points;
		REP(i,4)
		{
			FOR(j,i+1,4)
			{
				if(dist(v[i],v[j]) == maxi) { continue; }

				Point A(v[i].first, v[i].second), B(v[j].first, v[j].second);

				points.PB(pointReflectionOnALine(A, B, C));
			}
		}

		flag = false;
		REP(i,4)
		{
			printf("%lf %lf\n", points[i].first, points[i].second);
			LL x = (LL)points[i].first;
//			printf("%lld ", x);
			if(ABS(points[i].first-(double)x) < E)
			{
				LL y = (LL)points[i].second;
//				printf("%lld\n", y);
				if(ABS(points[i].second-(double)y) < E)
				{
				}
				else { flag = true; break; }
			}
			else { flag = true; break; }
		}

		if(flag) { printf("0\n"); continue; }

		double mini = (double)LLONG_MAX;
		REP(i,4) 
		{
			FOR(j,i+1,4)
			{
				double d = dist(points[i], points[j]);
				mini = MIN(mini, d);
			}
		}
		LL p = (LL)maxi;
		p %= BASE;
		printf("%lld\n", p);
	}

	return 0;
}
