
N,  M = map(int, input().split())

p = []
for x in range(N+M-1):
	p.append(float(input()))

def solve(n, m, dp = None):
	if dp is None:
		dp = {}
	if (n,m) in dp:
		return dp[(n,m)]

	if n == 0:
		return 0.0
	if m == 0:
		return 1.0

	p1 = 0.0
	p2 = 0.0
	i = N+M-n-m
	if p[i] == 0.0:
		dp[(n,m)] = solve(n-1, m, dp)
	elif p[i] == 1.0:
		dp[(n,m)] = solve(n, m-1, dp)
	else:
		dp[(n,m)] = p[i]*(solve(n, m-1, dp)) + (1-p[i])*solve(n-1, m, dp)
	return dp[(n,m)]


print('%.6f' %(solve(N,  M)))
