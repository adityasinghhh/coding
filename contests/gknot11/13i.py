def t(n, k):
	global T;
	if(T[n][k] != -1):
		return T[n][k];

	if(n == 0):
		T[n][k] = 1;
		return 1;
		
	if(k == 1):
		T[n][k] = 0;
		return 0;

	T[n][k] = (k-n)*t(n-1, k-1) + (n+1)*t(n, k-1);
	return T[n][k];

T = [];

for i in range(100):

	Ti = [];

	for j in range(100):
		Ti.append(-1);
	
	T.append(Ti);


for i in range(1, 100):
	for j in range(1, 100):
		t(i, j);

s = 0;
for i in range(30, 61):

	print T[i];
	for j in range(10, 21):

		s = (s+T[j][i]);

print s%1000000007;


