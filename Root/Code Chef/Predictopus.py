t = input()

while t > 0:
    t -= 1
    a = input()
    b = 1 - a
    if b > a:
        tmp = a
        a = b
        b = tmp
    ans = 10000 + (2*b*10000)*a - (10000*b)
    print ans
