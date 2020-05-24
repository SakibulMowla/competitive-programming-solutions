try:
    while 1:
        n = input()
        n += 1
        if n&1: n+=1
        print n+2 if n&1 else n+1
except:pass
