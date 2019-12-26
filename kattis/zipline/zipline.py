from math import sqrt, hypot
import sys

n = int(input())
for _ in range(n):
	w, g, h, r = map(float, input().split())
	g, h = min(g, h), max(g, h)
	ans1 = hypot( w, (h-g) )
	ans2 = 0.0

	f  = lambda x : hypot((g-r), x) + hypot((w-x), (h-r))
	fp = lambda x : x / hypot(g-r, x) - (w - x) / hypot(w-x, h-r)

	'''
	if abs(h-g) <= eps:
		print(ans1, ans1)
		continue

	a, b, c = (h**2 - g**2), 2*w*g**2, -1.0 * (g**2)*(w**2)
	x1 = (-b + sqrt(b*b - 4*a*c))/(2*a)
	x2 = (-b - sqrt(b*b - 4*a*c))/(2*a)
	print(ans1, max(f(x1), f(x2)))
	'''

	lo = 0
	hi = w
	mid = 0.0
	eps = 1e-8
	while hi - lo > eps:
		mid = (lo + hi) / 2
		if fp(mid) < 0:
			lo = mid
		else:
			hi = mid

	ans2 = f(mid)
	print('%.12f %.12f' %(ans1, ans2))


