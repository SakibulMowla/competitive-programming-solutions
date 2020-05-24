n = input()
if n % 2 == 0:
    print "-1"
else:
    for i in xrange(n):
        print "%d" % i ,
    print
    for i in xrange (n):
        print "%d" % ((i+1)%n) ,
    print
    for i in xrange(n):
        print "%d" % ((i+i+1) % n) ,
