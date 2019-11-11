
isVowel = lambda c : c.lower() in 'aoyeui'

s = list(input().strip())

for i in range(len(s)):
    s[i] = s[i].lower()
    if isVowel(s[i]):
        s[i] = ''
    else:
        s[i] = '.'+s[i]


print(''.join(s))

