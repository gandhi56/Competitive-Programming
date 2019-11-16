a = list(input().strip())
b = list(input().strip())
n = max(len(a), len(b))
while len(a) < n:
    a.insert(0, '0')

while len(b) < n:
    b.insert(0, '0')

aa = 0
bb = 0
for i in range(n):
    if ord(a[i]) < ord(b[i]):
        a[i] = ''
        aa += 1
    elif ord(a[i]) > ord(b[i]):
        b[i] = ''
        bb += 1

if aa == n:
    print('YODA')
else:
    print(int(''.join(a)))

if bb == n:
    print('YODA')
else:
    print(int(''.join(b)))
