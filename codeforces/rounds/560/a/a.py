n, x, y = map(int, input().split())
num = list(input().strip())
count = 0
for i in range(n-1, n-2-y, -1):
	if i == n-1-y and num[i] == '0':
		count += 1
		num[i] = '1'
	elif i > n-1-y and num[i] == '1':
		num[i] = '0'
		count += 1

print(count)
