#!/usr/bin/python

global a;

def f1(n):
	a = []
	a.append(0);
	a.append(1);
	a.append(3);

	for i in range(3, 50):
		if i&1:
			a.append(a[i-1]+a[i-2]+1);
		else:
			a.append(2*a[i-1]+1);

	return a[n];

def f2(n):
	a = []
	a.append(0);
	a.append(1);
	a.append(3);

	for i in range(3, 50):
		if i&1:
			a.append(a[i-1]+a[i-2]+1);
		else:
			a.append(2*a[i-1]+1);

	return a[n] - a[n-1];

def f3(n):
	if n < 10:
		if n < 0:
			return 0;
		elif n == 0:
			return 1;
		elif n < 8:
			return 2;
		else:
			return 3;

	s = str(n);
	l = len(s);

	cnt = 0;

	if s[0] == '9':
		cnt += f2(l);
	elif s[0] == '8':
		cnt += f2(l)/2;

		if l > 2:
			if s[l-1] == '9':
				s = s[:l-1] + '8';
			elif s[l-1] < '8':
				if s[1] != '0':
					x = long(s);
					while x%10 != 8:
						x -= 1;
					s = str(x);
				
			num = long(s[1:]);

			if num >= 8:
				num = long(s[1:len(s)-1]);
				cnt += f3(num);
	elif s[0] >= '2':
		cnt += f2(l)/2;
	elif s[0] == '1':
		if l > 2:
			if s[l-1] >= '1':
				s = s[:l-1] + '1';
			elif s[l-1] < '1':
				if s[1] != '0':
					x = long(s);
					while x%10 != 1:
						x -= 1;
					s = str(x);
				
			num = long(s[1:]);
	
			if num >= 1:
				num = long(s[1:len(s)-1]);
				cnt += f3(num);
		
	return cnt;

def f(n):
	if n < 10:
		if n < 0:
			return 0;
		elif n == 0:
			return 1;
		elif n < 8:
			return 2;
		else:
			return 3;

	s = str(n);
	l = len(s);

	cnt = f1(l);

	if s[0] == '9':
		cnt += f2(l);
	elif s[0] == '8':
		cnt += f2(l)/2;

		if l > 2:
			if s[l-1] == '9':
				s = s[:l-1] + '8';
			elif s[l-1] < '8':
				if s[1] != '0':
					x = long(s);
					while x%10 != 8:
						x -= 1;
					s = str(x);
				
			num = long(s[1:]);

			if num >= 8:
				num = long(s[1:len(s)-1]);
				cnt += f3(num);
	elif s[0] >= '2':
		cnt += f2(l)/2;
	elif s[0] == '1':
		if l > 2:
			if s[l-1] >= '1':
				s = s[:l-1] + '1';
			elif s[l-1] < '1':
				if s[1] != '0':
					x = long(s);
					while x%10 != 1:
						x -= 1;
					s = str(x);
	
			num = long(s[1:]);
	
			if num >= 1:
				num = long(s[1:len(s)-1]);
				cnt += f3(num);
		
	return cnt;

T = input();
while T:
	T -= 1;

	x = raw_input().split();

	a = long(x[0]);
	b = long(x[1]);

	print a-1, f(a-1);
	print b, f(b);
	print f(b) - f(a-1);
