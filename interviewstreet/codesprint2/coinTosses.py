#!/usr/bin/python

def f(N):
	return [2L**(N+1)-2L, 1L];

def f1(N, M):
	if N == M:
		return [0, 1];
	elif M == 0:
		return f(N);
	else:
		v1 = f1(N, M+1);
		v2 = f(N);

		v = [v1[0]*v2[1] + v1[1]*v2[0] + 2L*v1[1]*v2[1], 2L*v1[1]*v2[1]]

		return v;

def gcd(a, b):
	if a%b == 0:
		return b;
	return gcd(b, a%b);

T = int(raw_input());
while T:
	T -= 1;

	x = raw_input().split();
	N = long(x[0]);
	M = long(x[1]);

	ret = f1(N, M);

	g = gcd(ret[0], ret[1]);

	ret[0] /= g;
	ret[1] /= g;

	print str(ret[0]) + '.00';

#	print ret;

#	integer = long(ret);
#	decimal = str(ret - float(integer)) + '000';

#	print str(integer) + decimal[1:4];
