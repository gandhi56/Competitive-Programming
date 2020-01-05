import sys
for line in sys.stdin:
    a, b, c = map(int, line.split())
    if a == 0 and b == 0 and c == 0:
        break
    a,b,c = sorted([a,b,c])
    print('right' if a**2 + b**2 == c**2 else 'wrong')
