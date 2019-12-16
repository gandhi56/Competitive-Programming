from math import log, ceil
while True:
    try:
        num = int(raw_input())
        ans = 1
        for i in range(2, num+1):
            ans += log(i)/log(10)
        print(int(ans))
    except EOFError:
        break
