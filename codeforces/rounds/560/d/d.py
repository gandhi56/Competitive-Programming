t = int(input())
for _ in range(t):
	n = int(input())
	d = [int(s) for s in input().split()]

	if n == 1:
		ans = d[0]
		for x in range(d[0]+2, d[0]**2):
			if x%d[0] == 0:
				ans = "-1"
				break
		print(ans)

	d.sort()
	p = d[0]*d[-1]
	ok = True
	for i in range(0, len(d)//2):
		if d[i]*d[len(d)-1-i] != p:
			ok = False
			break

	if ok:
		print(p)
	else:
		print('-1')
