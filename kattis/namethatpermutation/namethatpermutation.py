from sys import stdin
from math import factorial as fact

vals = [0 for i in range(51)]
idp = [i for i in range(1, 51)]
ans = []

def convert(curr, base):
    if base < n+1:
        vals[n - base] = curr % base
        convert(curr // base, base+1)

def solve(step, m):
    if m != 0:
        cnt, i = -1, -1
        while cnt != vals[step]:
            i += 1
            if m&(1<<i):
                cnt += 1
        ans.append(str(idp[i]))
        solve(step+1, m&~(1<<i))

for line in stdin:
    ans.clear()
    n, k = map(int, line.split())
    convert(k, 1)
    solve(0, (1<<n)-1)
    print(' '.join(ans))
