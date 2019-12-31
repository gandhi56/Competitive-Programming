t = int(input())
for _ in range(t):
	k = input()
	p = [int(s) for s in input().split()]
	val = [s for s in input().split()]

	m = {}
	for i in range(len(p)):
		m[p[i]] = val[i]

	sm = sorted(m)

	for k in sm:
		print(m[k])

	if _ < t-1:
		print()
