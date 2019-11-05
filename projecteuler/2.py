tot = 2
x = 1
y = 2
while True:
    x, y = y, x+y
    if y > 4000000:
        break
    if y%2 == 0:
        tot += y
print(tot)
