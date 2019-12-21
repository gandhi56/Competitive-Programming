from sys import stdin

def base10(x, b):
    val = 0
    p = 1
    for i in range(len(x) - 1, -1, -1):
        val += int(x[i]) * p
        p *= b
    return val

def base10ToBase(x, b):
    val = 0
    p = 1
    while x > 0:
        val += (x % b) * p
        x //= b
        p *= 10
    return val

for line in stdin:
    line = line.split()
    if line[0] == '0':
        break
    b, p, m = int(line[0]), base10(line[1], int(line[0])), base10(line[2], int(line[0]))
    print(base10ToBase(p%m, b))

