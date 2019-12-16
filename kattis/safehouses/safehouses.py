
n = int(input())
grid = []
for i in range(n):
	grid.append(input().strip())


s = []
h = []
for i in range(n):
	for j in range(n):
		if grid[i][j] == 'S':
			s.append((i, j))
		elif grid[i][j] == 'H':
			h.append((i,j))


ans = 0
for spy in s:
	closest = 99999
	for house in h:
		dist = abs(spy[0] - house[0]) + abs(spy[1] - house[1])
		closest = min(closest, dist)
	ans = max(ans, closest)


print(ans)


