from math import e

bi, bo, ti, to, di, d0 = map(float, input().split())
s = float(input())

def f(lo, hi):
	return -e**((-hi*hi) / (2.0*s*s)) + e**((-lo*lo) / (2.0*s*s))

ans = 50.0*f(0,bi) + 25*f(bi, bo) + 10.5*f(bo, ti) + 31.5*f(ti, to) + 10.5*f(to, di) + 21*f(di, d0)

print(ans)
