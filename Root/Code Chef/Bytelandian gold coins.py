dp = {}
def rec(n):
    if n==0 :
        return 0
    elif n in dp:
        return dp[n]
    ret = rec(n//2) + rec(n//3) + rec(n//4)
    if ret < n :
        ret = n
    dp[n] = ret
    return ret


for i in range(0,10):
    n = raw_input()
    if len(n) == 0:
        break
    n = int(n)
    print rec(n)

