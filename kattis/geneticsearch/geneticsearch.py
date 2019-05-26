import sys

def countOccur(a, b):
	count = 0
	for i in range(len(b) - len(a) + 1):
		if a == b[i:i+len(a)]:
			count += 1
	return count

for line in sys.stdin:
	if line.strip() == '0':
		break
	a, b = line.split()
	t1, t2, t3 = countOccur(a, b), 0, 0
	subs = set()
	for i in range(len(a)):
		subs.add(a[:i]+a[i+1:])
	for s in subs:
		t2 += countOccur(s, b)
	
	adds = set()
	for i in range(len(a)+1):
		adds.add(a[:i]+'A'+a[i:])
		adds.add(a[:i]+'G'+a[i:])
		adds.add(a[:i]+'C'+a[i:])
		adds.add(a[:i]+'T'+a[i:])
	for s in adds:
		t3 += countOccur(s, b)
	print('{} {} {}'.format(t1, t2, t3))
