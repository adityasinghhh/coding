arr = [2,3,4,1,5]

res = 1;
for i in range(len(arr)):
	res = (31* res +arr[i])%1000003;
print res;
