from sys import stdin
species = {}
n = 0
for line in stdin:
	line = line.strip()
	if line == '':
		continue
	if line not in species:
		species[line] = 0
	species[line] += 1
	n += 1

for s in sorted(species):
	print('%s %.6f' %(s, species[s]*100 / n))

