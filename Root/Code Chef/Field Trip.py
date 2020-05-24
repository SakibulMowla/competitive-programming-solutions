import math

def m(a):
    return a

def main():

    var = 1010

    dp = [ [0]*var for i in xrange(var) ]

    for i in xrange(var):
        for j in xrange(0,i+1):
            if i == j or j == 0:
                dp[i][j] = 1
            elif j == 1:
                dp[i][j] = i
            else:
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
    
    for x in [0]*int(raw_input()):
        
        s,n,m,k = list(map(int, raw_input().split()))
        
        if k+1>n: print "0.000000"
        elif s==n: print "1.000000"
        else :
            a=0
            for i in range(k,m):
                if s-m < n-i-1 or m-1 < i or n-i-1 < 0:
                    continue
                c = dp[m-1][i] * dp[s-m][n-i-1]
                a = a+c
            b = dp[s-1][n-1]
            answer = 1.0
            answer = (a*1.0)/(b*1.0)
            print "%.6f" % answer
 
if __name__== "__main__":main()
