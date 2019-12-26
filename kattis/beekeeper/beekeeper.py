while True:
	n = int(input())
	if (n == 0):
		break
	best = 0
	ans = ""
	for i in range(n):
		s = input().strip()
		val = s.count('aa') + s.count('ee') + s.count('ii') + s.count('oo') + s.count('uu') + s.count('yy')
		if val >= best:
			best = val
			ans = s
	print(ans)
