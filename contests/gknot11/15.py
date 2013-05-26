from decimal import *;

getcontext().prec = 200;

f=Decimal(0);

for n in range(1, 10000000):
	if(n%2):
		f += (Decimal(n*n))/(Decimal(n*n*n+1));
	else:
		f -= (Decimal(n*n))/(Decimal(n*n*n+1));

print f;
