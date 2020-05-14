t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(s) for s in input().split()]
    seen = set()
    bad = False
    for i in range(n):
        if (i+a[i])%n in seen:
            bad = True
        seen.add((i+a[i])%n)
    if bad:
        print("NO")
    else:
        print("YES")
