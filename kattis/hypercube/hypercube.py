n, a, b = map(str, input().split())
n = int(n)

def binSearch(lo, hi, a, n, i, rev=False):
	mid = (lo+hi)//2
	if lo == hi:
		return lo
	if a[i] == '0':
		if rev:
			return binSearch(mid+1, hi, a, n-1, i+1, rev)
		else:
			return binSearch(lo, mid, a, n-1, i+1, rev)
	else:
		if rev:
			return binSearch(lo, mid, a, n-1, i+1, not rev)
		else:
			return binSearch(mid+1, hi, a, n-1, i+1, not rev)


print(binSearch(0, 2**n-1, b, n, 0) - binSearch(0, 2**n-1, a, n, 0) - 1)
