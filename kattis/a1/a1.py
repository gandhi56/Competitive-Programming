a2 = 2**(-.75)

def tapeLen(n, count):
	if n == 1:
		if count[2] >= 2:
			return 2 * a2
		else:
			return tapeLen(2, count)

	else:
		if count[n+1] >= 2:
			return 2 * 


a = 2**0.5

n = int(input())	# size of the smallest paper
sizes = [0,0] + [int(i) for i in input().split()]

# find the number of papers of the largest size
i = 2
while sizes[i] == 0:
	i += 1

currLen = sizes[i]

