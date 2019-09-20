n = int(input())
m = [[int(s) for s in input().split()] for k in range(n)]

a = [0 for i in range(n)]

for x in range(1, 10**9+1):
	a[0] = x
	done = True
	for i in range(1, n):
		a[i] = m[i-1][i] // a[i-1]
		if a[i] == 0:
			done = False
			break

	if done:
		break

print(a)
