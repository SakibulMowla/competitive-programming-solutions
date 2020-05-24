def gcd(a,b):
    if b==0: return a
    return gcd(b,a%b)

def sum(a,b,c):
    sum1 = a*c+ b
    sum2 = c
    n = gcd(sum1,sum2)
    sum1 = sum1 // n
    sum2 = sum2 // n
    return sum1,sum2

p,q = map(int ,raw_input().split())
i = gcd(p,q)
p = p // i
q = q // i

n = input()

arr = map(int ,raw_input().split())

if n == 1:
    if int(arr[0]) == p and 1 == q: print "YES"
    else: print "NO"

else:
    a = arr[0]
    b = 1
    c = arr[n-1]

    for i in range(n-2,-1,-1):
        if i != n-2:
            tmp = b
            b = c
            c = tmp
        a = arr[i]
        b,c = sum(a,b,c)
    
    if b==p and c==q: print "YES"
    else: print "NO"
