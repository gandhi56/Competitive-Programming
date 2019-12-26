
row, col, ld, rd = set(), set(), set(), set()

n = int(input())
for i in range(n):
	r, c = map(int, input().split())
	row.add(r)
	col.add(c)
	ld.add(r-c)
	rd.add(r+c)

print("CORRECT" if min(len(row), len(col), len(ld), len(rd)) == n else "INCORRECT")
