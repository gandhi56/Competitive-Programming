c = int(input())

for _ in range(c):
	inp = list(int(i) for i in input().split())[1:]
	ave = sum(inp)/len(inp)
	count = 0;
	for num in inp:
		if num > ave:
			count += 1
	print('%.3f%%'%(100*count/len(inp)))