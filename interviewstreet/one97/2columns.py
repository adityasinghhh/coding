v = [];
strings = raw_input().split();
for s in strings:
	v.append(s);

sz = len(v);

w = [];
s = v[0];
for i in range(1,sz):
	if len(s) + 1 + len(v[i]) < 40:
		s += ' ' + v[i];
	else:
		w.append(s);
		s = v[i];
w.append(s);

sz = len(w);
if sz%2 != 0:
	w.append('');
	sz += 1;

maxi = -1;
for i in range(sz/2):
	l = len(w[i]);
	maxi = max(maxi, l);
maxi += 10;

r = sz/2;
for i in range(sz/2):
	a = w[i];
	if w[i+r] != '':
		for j in range(maxi-len(w[i])):
			a += ' ';
		a += w[i+r];
	print a;
