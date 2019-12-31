
dp = {}
def f(u):
	if u in dp:
		return dp[u]

	if u not in adj:
		return c[u]
	best = 0
	for v in adj[u]:
		best = max(best, max(0.5*f(v) + c[u], f(v)))
	dp[u] = best
	return best

n, m = map(int, input().split())
c = list(map(int, input().split()))
adj = dict()

for i in range(m):
	s, t = map(int, input().split())
	if s in adj:
		adj[s].append(t)
	else:
		adj[s] = [t]

print(f(0))
