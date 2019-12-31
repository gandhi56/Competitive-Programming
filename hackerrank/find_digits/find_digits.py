t = int(input())
for _ in range(t):
    n = input()
    cnt = 0
    for d in n:
        if d == '0':
            continue
        if int(n) % int(d) == 0:
            cnt += 1
    print(cnt)
