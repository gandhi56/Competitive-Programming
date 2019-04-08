import sys
for line in sys.stdin:
	for i in range(len(line.strip())):
		if line[i:i+2] == '0x' or line[i:i+2] == '0X':
			j = i+2
			while line[j] in '0123456789abcdefABCDEF':
				j += 1
			print(line[i:j], int(line[i:j], 16))
			i = j-1
		i += 1
		
