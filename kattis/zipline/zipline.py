from math import sqrt
import sys

n = int(input())
for _ in range(n):
	w, g, h, r = map(float, input().split())
	g, h = min(g, h), max(g, h)
	lo = sqrt( w**2 + (h-g)**2 )
	x = (w*g - w*r) / (h+g - 2*r)
	hi = sqrt( (g-r)**2 + x**2 ) + sqrt( (h-r)**2 + (w-x)**2 )
	print(lo, hi)

