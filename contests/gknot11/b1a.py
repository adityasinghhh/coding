from decimal import *;

getcontext().prec = 500;

sumi = Decimal(0);
i = 1;
while(i <= 1000000):
		
	sumi = sumi + Decimal(i+2)/Decimal(i);
		
	i+=1;

print sumi;
