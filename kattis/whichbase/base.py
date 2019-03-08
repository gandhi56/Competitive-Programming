n = int(input())
for _ in range(n):
	a, n = input().split()
	x,y,z = 0,0,0
	try:
		x = int(n,8)
	except:
		pass

	try:
		y = int(n)
	except:
		pass

	try:
		z = int(n,16)
	except:
		pass

	print(a,x,y,z)
