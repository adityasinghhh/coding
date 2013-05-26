#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define MP make_pair
#define PD pair<double,double> 
#define MAX(a,b) ((a)<(b)?(b):(a));
#define MIN(a,b) ((a)>(b)?(b):(a));
typedef long long LL;
template<class T> inline int size(const T&c) { return c.size(); }
 
typedef int coord;
 
struct Point {
	coord x,y;
	Point() {}
	Point(coord x,coord y):x(x),y(y) {}
};
 
Point operator+(const Point &A,const Point&B) { return Point(A.x+B.x,A.y+B.y); }
Point operator-(const Point &A,const Point&B) { return Point(A.x-B.x,A.y-B.y); }
Point operator*(coord c, const Point &A) { return Point(c*A.x,c*A.y); }
coord operator^(const Point&A,const Point&B) { return A.x*B.y-A.y*B.x; }
coord operator*(const Point&A,const Point&B) { return A.x*B.x+A.y*B.y; }
coord len2(const Point&A) { return A*A; }
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
		int dot1 = X*Y;
		if(dot1 > 0) { return sqrt((double)len2(B-C)); }
		X = C-A; Y = A-B;
		int dot2 = (C-A)*(A-B);
		if(dot2 > 0) { return sqrt((double)len2(A-C)); }
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
	double det = A1*B1 - A2*B2;

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
 
vector<Point> points;
vector<Point> hull;
 
void cHull() {
	 
	int npoints = size(points);
	int start = 0;
	hull.clear();
	hull.push_back(points[0]);
	int nh = 1;
	FOR(i,1,npoints-1) {
		Point p = points[i];
		while(nh-start >= 2 && ((p-hull[nh-2])^(p-hull[nh-1])) >= 0) {
			--nh; hull.pop_back();
		}
		hull.push_back(p); ++nh;
	}
	start = nh-1;
	FORD(i,npoints-2,0) {
		Point p = points[i];
		while(nh-start >= 2 && ((p-hull[nh-2])^(p-hull[nh-1])) >= 0) {
			--nh; hull.pop_back();
		}
		hull.push_back(p); ++nh;
	}
	hull.pop_back();
}
 
int BruteForce() {
	int ans1 = 0,n=size(points);
	REP(i,n) FOR(j,i+1,n) FOR(k,j+1,n)ans1 >?= abs((points[j]-points[i])^(points[k]-points[i]));
	return ans1;
}
int area(int i,int j,int k) {
	 
	return abs((hull[j]-hull[i])^(hull[k]-hull[i]));
}
int Another() {
	 
	int len = hull.size();
	int ans=0 , i , j , k ;
	for(i=0;i<len;i++)
	{
		j=(i+1)%len;
		k=(j+1)%len;
		while(k!=i && area(i,j,k)<area(i,j,(k+1)%len))
		{
			k=(k+1)%len;
		}
		if(k==i)
			continue;
		int kk=(k+1)%len;
		while(j!=kk && k!=i)
		{
			ans=max(ans,area(i,j,k));
			while(k!=i && area(i,j,k)<area(i,j,(k+1)%len))
			{
				k=(k+1)%len;
			}
			j=(j+1)%len;
		}
	}
	printf("%d\n",ans);
}
int main() {
	Point A(2,3), B(5,8);
	printf("%lf %lf\n", (double)sqrt(len2(A)), (double)sqrt(len2(B)));
	 
/*	int kases; //kases = input();
	scanf("%d",&kases);
	int n,x,y;
	 
	while ( kases-- && scanf("%d",&n)) {
		points.clear();
		 
		REP(i,n) {
			//x = input();y = input();
			scanf("%d%d",&x,&y);
			points.push_back(Point(x,y));
		}
		sort(points.begin(),points.end());
		 
		cHull();
		 
		 
		n = hull.size();int t=0,i,j, ans = 0 , t1,t2,k,ans1=0;
		Another();
	}
*/
	return 0;
}
