def hash(s):
	l = len(s);
	r = 0;
	for i in range(l):
		r = r + ord(s[i]);

	return r;

f = open('hashing.c','r');
lines = f.readlines();
for line in lines:
	print line

	a = line[:97]
	b = line[101:]
	print a
	print b

	for i in range(9000, 10000):
		s = a + str(i) + b;
		if i == hash(s):
			print s;
		print i, hash(s);
