from math import sqrt

def isprime(num):
    for d in range(2, int(sqrt(num))+2):
        if num%d == 0:
            return False
    return True

t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    if a-b == 1 and isprime(a+b):
        print('YES')
    else:
        print('NO')
