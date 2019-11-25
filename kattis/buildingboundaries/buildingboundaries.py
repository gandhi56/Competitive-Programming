import itertools

def case1(x1, y1, x2, y2, x3, y3):
    # Three in a row
    return max(y1, y2, y3)*(x1+x2+x3)

def case2(x1, y1, x2, y2, x3, y3):
    # One left, two stacked on right
    return max(y1, y2+y3)*(x1 + max(x2, x3))

def case3(x1, y1, x2, y2, x3, y3):
    # One left, one below, one right
    if (y3 > y1) and (x2 > x1):
        # Invalid
        return -1
    elif (y3 > y1):
        return max(y1+y2, y3)*(x1+x3)
    elif (x2 > x1):
        return (y1+y2)*max(x1+x3, x2)
    else:
        return (y1+y2)*(x1+x3)

def check(x1, y1, x2, y2, x3, y3):
    mn = min(case1(x1, y1, x2, y2, x3, y3), case2(x1, y1, x2, y2, x3, y3))
    test3 = case3(x1, y1, x2, y2, x3, y3)
    if test3 == -1:
        return mn
    return min(mn, test3)

for _ in range(int(input())):
    a1, b1, a2, b2, a3, b3 = map(int, input().split())
    L = [(a1, b1), (a2, b2), (a3, b3)]
    mn = -1
    for l in itertools.permutations(L):
        for i in range(2):
            for j in range(2):
                for k in range(2):
                    x1, y1 = l[0][i], l[0][(i+1)%2]
                    x2, y2 = l[1][j], l[1][(j+1)%2]
                    x3, y3 = l[2][k], l[2][(k+1)%2]
                    val = check(x1, y1, x2, y2, x3, y3)
                    if mn == -1 or val < mn:
                        mn = val
    print(mn)
