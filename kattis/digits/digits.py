import sys

def solve(x0):
    if x0 == "1":
        return "1"
    i = 2
    a = x0
    b = str(len(x0))
    while True:
        a, b = b, str(len(b))
        if a == b:
            return i
        i += 1
    return -1

for line in sys.stdin:
    line = line.strip()
    if line == "END":
        break
    print(solve(line.strip()))
