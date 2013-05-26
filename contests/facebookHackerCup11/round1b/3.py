import math;
while 1:
	x = raw_input().split();

	n = long(x[0]);
	k = long(x[1]);

	if n==0 and k == 0:
		break;

	d = 1;

	while(d<=(k-1)*n):
		d = math.ceil(k*d*1./(k-1));

	print long(k*n+1-d);
