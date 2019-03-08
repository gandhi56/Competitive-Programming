
color = {}
def uncoloredNode():
	for i in color:
		if color[i] == 0:
			return i
	return -1

def colorable(g, u, col):
	for v in g[u]:
		if color[v] == col:
			return False
	return True

def solve(g, k):
	u = uncoloredNode()
	if u == -1:
		return True
	
	for c in range(1, k+1):
		if colorable(g, u, c):
			color[u] = c
			if solve(g, k):
				return True
			color[u] = 0
	return False

def main():
	n = int(input())
	g = {}
	delta = 0
	for i in range(n):
		g[i] = [int(j) for j in input().split()]
		color[i] = 0	# uncolored
		delta = max(delta, len(g[i]))

	for k in range(1, delta+2):
		color[0] = 1
		color[1] = 1
		if 1 in g[0]:
			color[1] = 2
		if solve(g, k):
			print(k)
			break

main()
