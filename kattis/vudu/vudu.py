n = int(input())
a = [int(s) for s in input().split()]
p = int(input())

bit = [0 for i in range(n)]
def add(i, delta):
	while i < n:
		bit[i] += delta
		i = i | (i+1)

def sum(r):
	ret = 0
	while r >= 0:
		ret += bit[r]
		r = (r & (r+1))-1
	return ret

def range_sum(l, r):
	return sum(r) - sum(l-1)


for i in range(len(a)):
	add(i, a[i])

count =0
for i in range(0, n):
	for j in range(i, n):
		if range_sum(i, j)/(j-i+1) >= p:
			count += 1

print(count)

