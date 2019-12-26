from sys import stdin

tp = [1]
while len(tp) <= 64:
    tp.append(tp[-1]*3)

for line in stdin:
    n = int(line)
    if n == 0:
        break
    if n == 1:
        print('{ }')
        continue
    n -= 1
    ans = []
    for i in range(len(tp)):
        if (1<<i)&n:
            ans.append(tp[i])
    print('{ ', end='')
    for i in range(len(ans)):
        print(ans[i], end='')
        if i < len(ans)-1:
            print(', ', end='')
    print(' }')
