numbers = [];
four = {};
for i in range(1000):
	numbers.append(i*4);
	four[i*4] = i;

x = {};
seven = {};
for i in range(1000):
	for number in numbers:
		if i*7 + number > 1000:
			break;
		four[i*7 + number] = four[number];
		seven[i*7 + number] = i;
		x[i*7 + number] = 1;

keys = x.keys();
keys.sort();
print keys;

for i in range(1000):
	if four.has_key(i):
		print i, four[i], seven[i];
