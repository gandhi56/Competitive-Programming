s = "welcome to code jam"

def solve(sent, i=0):
    cnt = 0
    if i == len(s) - 1:
        for c in sent:
            if c == 'm':
                cnt += 1
        return cnt
    for j in enumerate(sent):
        if j[1] == s[i]:
            cnt += solve(sent[j[0] + 1:], i+1)
    return cnt

t = int(input())
for t in range(1, t+1):
    ans = solve(input())
    if ans < 10:
        print('Case #{}: 000{}'.format(t, ans))
    elif ans < 100:
        print('Case #{}: 00{}'.format(t, ans))
    elif ans < 1000:
        print('Case #{}: 0{}'.format(t, ans))
    else:
        print('Case #{}: {}'.format(t, ans))
