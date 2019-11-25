c = float(input())
l = int(input())
sum = 0.0
for i in range(l):
    w, h = map(float, input().split())
    sum += w*h

print("%.8f" %(sum*c))