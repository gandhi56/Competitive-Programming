from sys import stdin

d = {}
read = True
for line in stdin:
	line = line.strip()
	if line == "":
		read = False
		continue
	if read:
		v,k = map(str,line.split())
		d[k] = v
	else:
		if line in d:
			print(d[line])
		else:
			print("eh")
