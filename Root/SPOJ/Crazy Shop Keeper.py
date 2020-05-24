t = input()
while t > 0:
    t -= 1
    n,x = map(int ,raw_input().split())
    ans = n
    while n >= x:
        ans += (n//x)
        n = (n//x) + (n%x)
    print ans
