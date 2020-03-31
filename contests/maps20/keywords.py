n = int(input())
words = set()
for i in range(n):
    s = input().strip()
    s = s.replace('-', ' ')
    words.add(s.lower())
print(len(words))
