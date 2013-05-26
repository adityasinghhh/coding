import math
def gcd(a, b):
	if a%b == 0:
		return b
	return gcd(b, a%b);

a = long(math.pow(2, 80));
b = 61305790721611591

g = gcd(a, b);

print g;

a = a/g;
b = b/g;

print a+b;
