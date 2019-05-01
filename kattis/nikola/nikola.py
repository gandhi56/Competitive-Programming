n = int(input())
c = [-1]
for i in range(n):
	c.append(int(input()))

INF = 9999999

dp = {}
def solve(pos, jump, cost_so_far):
	if (pos,jump) in dp.keys():
		return dp[(pos, jump)]
	if pos == n:
		dp[(pos,jump)] = cost_so_far
	else:
		fpos = pos+jump+1
		bpos = pos-jump

		fsol = INF
		if fpos <= n:
			fsol = solve(fpos, jump+1, cost_so_far + c[fpos])

		bsol = INF
		if bpos > 0:
			bsol = solve(bpos, jump, cost_so_far + c[bpos])

		dp[(pos,jump)] = min(fsol, bsol)
	return dp[(pos,jump)]

print(solve(2, 1, c[2]))

