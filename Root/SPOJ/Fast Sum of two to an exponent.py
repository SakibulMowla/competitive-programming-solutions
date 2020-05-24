from sys import stdin,stdout

mod = 1298074214633706835075030044377087

arr = [0] * 510

two = 1
arr[0] = 1
for i in range(1,501):
    two = (two * 2) % mod
    arr[i] = (arr[i-1] + two) % mod
    
t = int(stdin.readline().strip())

while t > 0:
    t = t - 1
    n = int(stdin.readline().strip())
    print arr[n]
