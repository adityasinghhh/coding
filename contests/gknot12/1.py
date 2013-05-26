cnt = 0;
for a1 in range(2):
	for a2 in range(2):
		for a3 in range(2):
			for a4 in range(2):
				for a5 in range(2):
					for a6 in range(2):
						for a7 in range(2):
							for a8 in range(2):
								for a9 in range(2):
									if (a1 == 1 and a2 == 1 and a4 == 1 and a5 ==1) or (a2 == 1 and a3 == 1 and a5 == 1 and a6 == 1) or (a4 == 1 and a5 == 1 and a7 == 1 and a8 ==1) or (a5 == 1 and a6 == 1 and a8 == 1 and a9 == 1):
												continue;
									cnt += 1;

print cnt;
			

