from sys import stdin

for line in stdin:
    line = line.split()
    if line[0] == '0':
        break
    b = int(line[0])
    p, m = int(line[1], b), int(line[2])


