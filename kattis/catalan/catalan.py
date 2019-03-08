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

q = int(input())
for _ in range(q):
	x = int(input())
	print(catalan(x))



