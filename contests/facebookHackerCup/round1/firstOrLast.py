#!/usr/bin/python
#maxi = -1.0;
def gcd(a, b):
	if(a%b == 0):
		return b;
	return gcd(b, a%b);

def f(i, R, num, den):
	global dic, maxi, maxnum, maxden, r, t, a1, a0, b1, b0;
	if R >= r:
		return (maxi, maxnum, maxden);

	if dic.has_key((i, R, num, den)):
		return dic[(i, R, num, den)];

	if(i == t):
		if(r-1 == R):
			g = gcd(den, num);

			val = float(num/g)/float(den/g);

			if(val > maxi):
				maxi = val;
				maxnum = num/g;
				maxden = den/g;
				print maxi, maxnum, maxden;
		return (maxi, maxnum, maxden);

	if(r-1 == R):
		num *= b0[i];
		den *= b1[i];

		g = gcd(den, num);

		dic[(i, R, num, den)] = f(i+1, R, num/g, den/g);
		return dic[(i, R, num, den)];
	else:
		num1 = num*a0[i];
		den1 = den*a1[i];

		g = gcd(den1, num1);

		v1 = f(i+1, R+1, num1/g, den1/g);

		num1 = num*b0[i];
		den1 = den*b1[i];

		g = gcd(den1, num1);

		v2 = f(i+1, R, num1/g, den1/g);

		if v1 > v2:
			dic[(i, R, num, den)] = v1;			
			return v1;
		dic[(i, R, num, den)] = v2;			
		return v2;

#global maxi, maxnum, maxden, r, t, a1, a0, b1, b0;
no = input();

while no:
	x = raw_input();
	x = x.split();
	
	r = int(x[0]);
	t = int(x[1]);

	l = len(x);

	a1 = [];
	a0 = [];
	b1 = [];
	b0 = [];
	dic = {};

	i = 2;
	j = 0;
	while i < l:
		a1.append(int(x[i]));
		b1.append(int(x[i+1]));

		a0.append(a1[j]-1);
		b0.append(b1[j]-1);

		j += 1;
		i += 2;

	maxi = -1.0;
	f(0, 0, 1, 1);

	print str(maxnum) + '/' + str(maxden);
	no -= 1;
