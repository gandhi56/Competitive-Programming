from math import e
n = int(input())

ans = 1/e

if n < 50:
	f = 1
	ans = 1
	for i in range(1, n+1):
		f *= i
		if i % 2 == 0:
			ans += 1.0/f
		else:
			ans -= 1.0/f
print("%.8f"%(1-ans))

