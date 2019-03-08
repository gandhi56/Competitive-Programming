n = int(input())

rooms = []

def disjoint(a, b):
	return a[1] < b[0]

def union(a, b):
	# assume a[1] >= b[0]
	return [min(a[0], b[0]), max(a[1], b[1])]

for _ in range(n):
	l, u = map(int, input().split())
	
	if len(rooms) == 0:
		rooms.append([l, u])
		continue

	for i in range(len(rooms)):
		if disjoint(rooms[i], [l, u]):
			rooms.append([l, u])
		else:
			rooms[i] = [min(rooms[i][0], l), max(rooms[i][1], u)]

print(rooms)

print(len(rooms))
