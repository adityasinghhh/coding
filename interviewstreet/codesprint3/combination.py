
F = [None]*1010;
F[0] = 1L;
for i in range(1000):
	F[i+1] = F[i]*(i+1);
	print i, F[i];

mod = 142857L;

for i in range(1000):
	for j in range(i+1):

		print i, j, (F[i]/F[j]/F[i-j]) % mod;
