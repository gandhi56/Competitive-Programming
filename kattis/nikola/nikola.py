n = int(input())
c = [-1]
for i in range(n):
	c.append(int(input()))

dp = {}
def solve(i, j):
	print(i)
	if i <= 0 or i > n:
		return 999999
	if (i,j) in dp:
		return dp[(i,j)]
	if i == n:
		dp[(i,j)] = c[n]
	dp[(i,j)] = min(solve(i+j+1, j+1), solve(i-j, j))

	return dp[(i,j)]

print(solve(1, 1))

