import math

m, n, t = map(int, input().split())

ans = True
if t == 1:
	if n <= 15:
		ans = m < math.factorial(n)

elif t == 2:
	ans = m < 2**n
elif t == 3:
	ans = m < n**4
elif t == 4:
	ans = m < n**3
elif t == 5:
	ans = m < n**2
elif t == 6:
	ans = m < n*math.log(n, 2)
elif t == 7:
	ans = m < n
if ans:
	print("TLE")
else:
	print("AC")
