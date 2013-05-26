import math;
def PellSolution(D):
	Pn = [0]*100;
	Qn = [0]*100;
	a = [0]*100;
	p = [0]*100;
	q = [0]*100;
	if(math.sqrt(D))!=math.floor(math.sqrt(D)):
		Pn[0]=0;Qn[0]=1;
		a[0]=long(math.floor(math.sqrt(D)));
	        p[0]=a[0];q[0]=1;
	 
	        n=1;
	        Pn[1]=a[0];Qn[1]=D-a[0]*a[0];
	        a[1]=long(math.floor((a[0]+Pn[1])/Qn[1]));
	        p[1]=long(a[0]*a[1]+1.0);
	        q[1]=a[1];
	 
	        while (a[n]!=long(2.0*a[0])):
	        	n=n+1;
	                Pn[n]=a[n-1]*Qn[n-1]-Pn[n-1];
	                Qn[n]=long((D-Pn[n]*Pn[n])/Qn[n-1]);
	                a[n]=long(math.floor((a[0]+Pn[n])/Qn[n]));
	                p[n]=a[n]*p[n-1]+p[n-2];
	                q[n]=a[n]*q[n-1]+q[n-2];
	        r=n-1;
	        if (r%2==0):
			for n in range(r+2, 2*r+2):
	                	Pn[n]=a[n-1]*Qn[n-1]-Pn[n-1];
		                Qn[n]=long((D-Pn[n]*Pn[n])/Qn[n-1]);
		                a[n]=long(math.floor((a[0]+Pn[n])/Qn[n]));
	        	        p[n]=a[n]*p[n-1]+p[n-2];
	                	q[n]=a[n]*q[n-1]+q[n-2];
	             	x1=p[2*r+1];
	             	y1=q[2*r+1];
		else:
	        	x1=p[r];
	                y1=q[r];
	        return [long(x1), long(y1)];
	else:
	        return [0, 0];
x = -1
for i in range(1, 1001):
	ans = PellSolution(i);

	print ans[0];

	if x < ans[0]:
		v = i;
		x = ans[0];

print v;
