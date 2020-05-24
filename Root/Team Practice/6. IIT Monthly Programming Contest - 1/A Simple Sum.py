import math

def BigMod(B, P, M):
    R = 1%M
    while P>0:
        if P%2==1:
            R = (R*B)%M
        P = P/2
        B = (B*B)%M
    return R

def main():
    for x in [0]*int(raw_input()):
        x, m, n = list(map(int, raw_input().split()))
        if x == 1:
            ans = (m+1) % n
            print ans
        else:
            ans = BigMod(x, m+1, n*(x-1))
            ans = (ans - 1 + n*(x-1)) % (n*(x-1))
            ans = ans / (x-1)
            ans = ans % n
            print ans
if __name__== "__main__":main()
