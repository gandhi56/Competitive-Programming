n = int(input())

d = 2
factors = []
while d*d <= n:
    if n%d == 0:
        factors.append(d)
    while n%d == 0:
        n //= d
    d += 1
if n > 1:
    factors.append(n)
print(max(factors))
