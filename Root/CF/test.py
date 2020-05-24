n,k=map(int,raw_input().split())
r=n-k
while n:print[r+1-n,n][n>r],;n-=1
