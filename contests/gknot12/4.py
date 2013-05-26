import sys;
sys.setrecursionlimit(10000000)

def f(a, b):
	x = 0; y = 1; lastx = 1; lasty = 0;
	while(b):
		q = a/b;
		t = a; a = b; b = t%b;
		t = x; x = lastx - q*x; lastx = t;
		t = y; y = lasty - q*y; lasty = t;

	return [lastx, lasty];

a = [6, 357, 15, 10432664, 136, 4, 41];
b = [109, 359, 97, 11234549, 317, 59, 47];

l = len(a);

M = 1L;
for i in range(l):
	M *= b[i];

print M;

x = 0L;
for i in range(l):
	
	Mi = M/b[i];
	
	r =  f(Mi, b[i]);

	print r[0] * Mi + r[1] * b[i];

	x += a[i] * r[0] * Mi;
#	x += a[i]*f(Mi, b[i])*Mi;

print 'here';
print x % M;
