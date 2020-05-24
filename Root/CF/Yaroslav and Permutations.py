n = input()

ara = map(int , raw_input().split())

best = max(ara.count(x) for x in ara)

if(best <= (n-best+1)):
    print "YES"
else:
    print "NO"
