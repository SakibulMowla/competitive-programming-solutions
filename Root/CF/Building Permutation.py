n = input()
arr = map( int , raw_input().split() )
arr.sort()

ans = 0

for i in range(n):
    ans += abs( i+1 - arr[i] )
print ans
