
from math import acos, sin
a,b,c,d = map(int, input().split())
ang = acos((c*c + d*d - a*a - b*b) / (-2*c*d - 2*a*b))
print('%.8f'%((a*b + c*d) * sin(ang)/2))
