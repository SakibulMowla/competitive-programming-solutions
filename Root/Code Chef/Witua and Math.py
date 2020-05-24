import math

prime = [1,2,3,11,111,1111,1111,11111,11111,111111]

def bigmod(b,p,m):
    r = 1
    while p > 0:
        if p % 2 == 1:
            r = (r * b) % m
        p = p // 2
        b = (b * b) % m
    return r


def check(n):
    for i in range(10):
        
        a = prime[i]
        if a >= n :
            continue

        d = n - 1
        s = 0
        
        while d % 2 == 0:
            s += 1
            d = d / 2
        
        if bigmod(a,d,n) == 1:
            continue
        
        flag = 0
        for r in range(0,s):
            if bigmod(a,(2**r)*d,n) == n-1:
                flag = 1
                break
            
        if flag == 0:
            return 0
        
    return 1
        
        

def find(n):
    if n == 2:
        return 2
    if n%2 == 0:
        n -= 1
    i = n
    while i >= 0:
        if check(i) == 1:
            return i
        i -= 2
        
        
def main():
    for x in [0]*int(raw_input()):
        n = input()
        n = int(n)
        print find(n)
if __name__== "__main__":main()
