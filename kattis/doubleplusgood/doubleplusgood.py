expr = raw_input().split('+')

n = len(expr)
ans = set()
cnt = 0
for m in range(0, 2**(n-1)):
    b = [expr[0]]
    for i in range(1, n):
        if (m&(1<<(i-1))):
            b[-1] += expr[i]
        else:
            b.append(expr[i])

    for i in range(len(b)):
        b[i] = int(b[i])
    ans.add(sum(b))

print(len(ans))

