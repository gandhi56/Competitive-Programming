
def get_pos(c):
	if c == '.':
		return 3,3

	r = (ord(c)-ord('A'))//4
	c = (ord(c)-ord('A'))%4
	return r,c

g = []
for _ in range(4):
	g.append(input().strip())

cost = 0
for i in range(4):
	for j in range(4):
		if g[i][j] == '.':
			continue
		pos = get_pos(g[i][j])
		cost += abs(i - pos[0]) + abs(j - pos[1])
print(cost)
