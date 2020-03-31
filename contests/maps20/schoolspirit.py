
cs = 4/5

def score(sl):
    sc = 0.0
    for i in range(len(sl)):
        sc += sl[i] * cs**i
    return sc / 5

def gscore(sl, k):
    sc = 0.0
    p = 0
    for i in range(len(sl)):
        if i == k:
            continue
        sc += sl[i] * cs**p
        p += 1
    return sc / 5

n = int(input())
s = []
for i in range(n):
    s.append(float(input()))

currscore = score(s)

tot = 0
for i in range(n):
    tot += gscore(s, i)
ave = tot/n

print(currscore)
print(ave)


