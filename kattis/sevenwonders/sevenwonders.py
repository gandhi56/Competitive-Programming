n = input().strip()
t = n.count('T')
c = n.count('C')
g = n.count('G')
print(t*t + c*c + g*g + 7*min(t, c, g))
