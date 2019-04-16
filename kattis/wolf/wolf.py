def solve(n):
	if n != 26:
		return n > 26
	suit = [[0] for i in range(4)]
	for i in range(n):
		v, s = map(str, input().split())
		suit['CDHS'.find(s)].append(int(v))
	
	for i in range(4):
		if max(suit[i]) > len(suit[i])-1:
			return True
	return False

print(['impossible', 'possible'][solve(int(input()))])
