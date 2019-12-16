a = 1
b = 1
cnt = 1
while True:
    a, b = b, a+b
    if str(b) == 1000:
        break
    print(cnt)
    cnt += 1
print(b)
