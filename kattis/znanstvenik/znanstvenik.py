r, c = map(int, input().split())
g = [input().strip() for i in range(r)]

s = []
for j in range(c):
	s.append([])
	for i in range(r):
		s[j].append(g[j][i])

s.sort()
print(s)
