from decimal import *;
from math import *;

getcontext().prec = 200;

f = (Decimal(1) - Decimal(str(log(2.0))) + Decimal(str(pi))/(Decimal(str(cosh(sqrt(3.0))))*Decimal(str(pi)))/Decimal(2))/Decimal(3);

print Decimal(str(pi));
print f;
