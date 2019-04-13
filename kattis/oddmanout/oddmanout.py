m = dict()

n = int(input())
for t in range(1, n+1):
	m.clear()
	k = int(input())
	for num in [int(i) for i in input().split()]:
		if num not in m.keys():
			m[num] = 0
		m[num] += 1

	for k in m.keys():
		if m[k] == 1:
			print("Case #{}: {}".format(t, k))
			break
