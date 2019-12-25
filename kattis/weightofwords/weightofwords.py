l, w = map(int, input().split())

if l > w or 26*l < w:
    print('impossible')
else:
    word = ['?' for i in range(l)]
    chars = '#abcdefghijklmnopqrstuvwxyz'
    for i in range(l-1, -1, -1):
        d = 26
        while w-d < i:
            d -= 1
        word[i] = chars[d]
        w -= d
    print(''.join(word))

