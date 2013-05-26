#include<cstdio>
#include<cmath>
int main()
{
	int x1, x2, x3, x4, y1,y2,y3,y4,count = 0;
	double s1,s2,s3,s4,d1,d2,angle12,angle23,angle34,angle41;
	for(x1 = 1; x1<=10; x1++)
		for(y1 = 1; y1<=10; y1++)
			for(x2 = -10; x2<=-1; x2++)
				for(y2 = 1; y2<=10; y2++)
					for(x3 = -10; x3<=-1; x3++)
						for(y3 = -10; y3<=-1; y3++)
							for(x4 = 1; x4<=10; x4++)
								for(y4 = -10; y4<=-1; y4++) {

									s1 = sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
									s2 = sqrt((double)((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3)));
									s3 = sqrt((double)((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4)));
									s4 = sqrt((double)((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1)));
									d1 = sqrt((double)((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3)));
									d2 = sqrt((double)((x2-x4)*(x2-x4)+(y2-y4)*(y2-y4)));

									angle12 = (s1*s1 + s2*s2 - d1*d1)/(2.0*s1*s2);
									angle23 = (s2*s2 + s3*s3 - d2*d2)/(2.0*s2*s3);
									angle34 = (s3*s3 + s4*s4 - d1*d1)/(2.0*s3*s4);
									angle41 = (s4*s4 + s1*s1 - d2*d2)/(2.0*s4*s1);

//									printf("%lf %lf %lf\n", angle12, angle34, angle12+angle34);
									if(acos(angle12)+acos(angle34)-M_PI < 0.000001)
										count++;
								}

	printf("%d\n", count);

}
