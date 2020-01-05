d = input().strip()
cards = [s for s in input().split()]
done = False
for c in cards:
    if c[0] == d[0] or c[1] == d[1]:
        print('YES')
        done =  True
        break

if not done:
    print('NO')
