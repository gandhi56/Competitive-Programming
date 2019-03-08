
from math import acos

splats = []

c = int(input())
for _ in range(c):
	n = int(input())	# number of paint drops
	for i in range(n):
		
		# (x, y) = location of paint drop, v = volume
		inp = [i for i in input().split()]
		x = float(inp[0])
		y = float(inp[1])
		v = float(inp[2])
		col = inp[3]
		rad = (v / acos(-1)) ** 0.5
		splats.append((x, y, v, rad, col))

	m = int(input())
	for i in range(m):
		x, y = [float(i) for i in input().split()]

		ans = "white"
		for j in range(len(splats)-1, -1, -1):
			dx = x - splats[j][0]
			dy = y - splats[j][1]

			if dx*dx + dy*dy <= splats[j][3]*splats[j][3] + 1e-8:
				ans = splats[j][4]
				break

		print(ans)

