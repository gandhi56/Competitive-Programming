memo = {0:1, 1:1}

def catalan(n):
	if n in memo:
		return memo[n]

	if n <= 500:
		memo[n] = ((n << 2) - 2) * catalan(n-1) // (n + 1)
	else:
		catalan(n - 500)
		memo[n] = ((n << 2) - 2) * catalan(n-1) // (n + 1)

	return memo[n]

catalan(5000)

n = int(input())
s = 0
for k in range(0, n+1):
	s += catalan(k) * catalan(n-k)
print(s)
