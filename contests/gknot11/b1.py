from decimal import *;
from math import *;

getcontext().prec = 200;
s = Decimal(0);
for m in range(2, 1000001):
	for n in range(1, 100):
		sq = sqrt(n);

		x = sq-float(int(sq));

		if x < 0.5000000000000:
			sq = x;
		else:
			sq = x+1.0;

		v = Decimal(str((pow(Decimal(m), 2.0*sq) + 1.0)/pow(Decimal(m), sq+float(n))));

		s += v;

print s;



