
dp = {}
def solve(n):
	if n in dp:
		return dp[n]
	if n <= 0:
		dp[n] = 0; return dp[n]
	if n%10 == 0:
		dp[n] = 10 * solve(n//10) + 45 * (n//10); return dp[n]
	else:
		dp[n] = solve(n-1) + sum(int(x) for x in str(n-1))
	return dp[n]

for t in range(int(input())):
	a,b = [int(x) for x in input().split()]
	print(solve(b+1) - solve(a))
