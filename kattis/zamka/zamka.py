
def ds(x):
    return sum([int(x) for x in list(str(x))])

l = int(input())
d = int(input())
x = int(input())

for n in range(l, d+1):
    if ds(n) == x:
        print(n)
        break


for n in range(d, l-1, -1):
    if ds(n) == x:
        print(n)
        break

