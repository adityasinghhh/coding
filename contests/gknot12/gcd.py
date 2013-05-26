def gcd(a, b):
	if b == 0:
		return a;
	return gcd(b, a%b);

b = 2991816
a = 23882040;

g = gcd(a, b);

print g, b/g, a/g
