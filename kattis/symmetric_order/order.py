
t = 1
while 1:
	n = int(input())
	if n == 0:
		break
	names = []
	for i in range(n):
		names.append(input().strip())

	print("SET", t)
	for i in range(0, len(names), 2):
		print(names[i])

	if n%2 == 0:
		for i in range(len(names)-1, 0, -2):
			print(names[i])
	else:
		for i in range(n-2, 0, -2):
			print(names[i])

	t += 1
