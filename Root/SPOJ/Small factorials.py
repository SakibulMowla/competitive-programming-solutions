import math

t = input()
arr = []

arr.append(1)

for i in range(1,101):
    arr.append(i * arr[i-1])

while t>0:
    t -= 1
    n = input()
    print arr[n]
