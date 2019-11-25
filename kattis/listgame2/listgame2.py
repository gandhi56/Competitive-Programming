x = int(input())
d = 2
count = 0
while d*d <= x:
	if x%d == 0:
		count += 1
	while x%d == 0:
		x //= d
	d += 1

if x > 1:
	count += 1

print(count)
