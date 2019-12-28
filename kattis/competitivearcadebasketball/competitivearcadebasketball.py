n, p, m = map(int, input().split())

players = {}
for i in range(n):
	name = input().strip()
	players[name] = [0, False]

count = 0
for i in range(m):
	name, points = [s for s in input().split()]
	players[name][0] += int(points)

	if players[name][0] >= p and players[name][1] is False:
		print(name, 'wins!')
		count += 1
		players[name][1] = True

if count == 0:
	print('No winner!')
