
mark = [True]*1002

def get_col(grid, i):
	col = ""
	for k in range(len(grid)):
		col += grid[k][i]
	return col

def valid_grid(grid):
	for i in range(len(grid[0])):
		if not mark[i]:
			continue
		col1 = get_col(grid, i)
		for j in range(i+1, len(grid[0])):
			if not mark[j]:
				continue
			col2 = get_col(grid, j)
			if col1 == col2:
				return False
	return True

def solve(grid):
	if not valid_grid(grid):
		print(grid)
		return True

	for i in range(len(grid)):
		mark[i] = False
		if solve(grid):
			return True
		mark[i] = True

	return False

def main():
	r, c = map(int,input().split())
	grid = []
	for i in range(r):
		grid.append(input().strip())

	solve(grid)

main()
