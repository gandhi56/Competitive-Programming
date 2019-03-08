n, m = map(int, input().split())

def solve(n, m):
	n, m = min(n,m), max(n,m)
	if m % n == 0 or 2*n < m:
		return "win"
	elif solve(m-n, n) == "win":
		return "lose"
	else:
		return "win"

print(solve(n, m))
