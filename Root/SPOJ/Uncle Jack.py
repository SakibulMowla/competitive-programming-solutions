def bigmod(b,p):
    r = 1
    while p > 0:
        if p % 2 == 1:
            r = (r * b)
        p = p // 2
        b = (b * b)
    return r

while True:
    n,d = raw_input().split()
    n = int(n)
    d = int(d)
    if n == 0 and d == 0 : break
    print bigmod(n,d)
