def gcd(a, b):
	if a%b == 0:
		return b;
	return gcd(b, a%b);

s = 0;

for n in range(2, 41):
	total = 2*n;

	num = 1;
	den = 1;

	while total != 0:

		total -= 1;

		if total-1 == 0:
			break;

		num *= (total-1);
		den *= total;
		total -= 1;

		g = gcd(den, num);

		num /= g;
		den /= g;
		
		
	s += num+den;
	print num, den, num+den, s;

print s;
		
