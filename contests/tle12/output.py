f0 = open('input','r');
f1 = open('out','r');
f2 = open('output','r');
l0 = f0.readlines();
l1 = f1.readlines();
l2 = f2.readlines();
l = len(l1);
for i in range(l):
	line1 = l1[i][:len(l1[i])-1]
	line2 = l2[i][:len(l2[i])-1]

	if line1 == line2:
		continue;

	len1 = len(line1);
	for j in range(len1):
		if line1[j:j+1] != line2[j:j+1]:
			print i, ': ', line1, line2, line1[j], line2[j], j, l0[i][j];
	

