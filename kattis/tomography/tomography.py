input()
rows = [int(x) for x in input().split()]
cols = [int(x) for x in input().split()]
rr = rows[:]
cc = cols[:]

for n in rows:
	cc.sort(reverse=True)
	for i in range(n):
		cc[i] -= 1

	if -1 in cc:
		break

for n in cols:
	rr.sort(reverse=True)
	for i in range(n):
		rr[i] -= 1

	if -1 in rr:
		break

if -1 in cc or -1 in rr:
	print("No")
else:	
	print('Yes')
