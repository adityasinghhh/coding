for N in range(1,100):
	for M in range(1,max(2*N+1,100)):
		cnt = 0;
		for a in range(1,N+1):
			for b in range(a+1,N+1):
				if (a + b)%M == 0:
					cnt += 1;

		print N, M, cnt;
