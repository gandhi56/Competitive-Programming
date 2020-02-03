from sys import stdin
m = {}
for line in stdin:
    line = line.strip()
    if line == '':
        break
    v, k = map(str, line.split())
    m[k] = v

for lin in stdin:
    lin = lin.strip()
    if lin in m:
        print(m[lin])
    else:
        print('eh')
