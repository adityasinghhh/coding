#!/usr/bin/python
def gcd(a, b):
	if a%b == 0:
		return b;
	return gcd(b, a%b);

no = input();

while no:
	x = raw_input();

	x = x.split();

	r = int(x[0]);
	t = int(x[1]);

	l = len(x);

	j = 0;
	i = 2;
	a = [];
	b = [];
	a_val = [];
	b_val = [];

	while i < l:
		p = int(x[i]);
		q = int(x[i+1]);

		a.append(p);
		a_val.append(1.0/float(p));
		b.append(q);
		b_val.append(1.0/float(q));

		i += 2;

#	print a_val;
#	print a;
#	print b_val;
#	print b;

	for i in range(t):
		for j in range(i+1, t):
			if b_val[i]-a_val[i] < b_val[j]-a_val[j]:
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				temp = b_val[i];
				b_val[i] = b_val[j];
				b_val[j] = temp;
				temp = a_val[i];
				a_val[i] = a_val[j];
				a_val[j] = temp;
#	print;
#	print a_val;
#	print a;
#	print b_val;
#	print b;


	num = 1;
	den = 1;

	for i in range(t):
		if i < r-1:
			num *= a[i]-1;
			den *= a[i];
		else:
			num *= b[i]-1;
			den *= b[i];

#	print den, num;
	g = gcd(den, num);

#	print den, num;
	print str(num/g) + '/' + str(den/g);

	no -= 1;
