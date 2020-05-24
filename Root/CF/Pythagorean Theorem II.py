import math

n = input()
n = int (n)
cnt = 0 

for a in range (1,n+1):
    for b in range(a,n+1):
        c = a**2 + b**2
        d = math.sqrt(c)
        if int(d) > n:
            break
        if d == int(d):
            cnt += 1

print cnt
