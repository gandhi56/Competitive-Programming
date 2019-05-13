import sys

dp = {}
def solve(n):
	if n in dp:
		return dp[n]
	if n <= 1:
		dp[n] = 0
	dp[n] = max(n, solve(n//2) + solve(n//3) + solve(n//4))
	return dp[n]

for line in sys.stdin:
	n = int(line)
	print(solve(n))
