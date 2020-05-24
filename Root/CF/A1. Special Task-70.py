mark = [0] * 300
s = raw_input()
m = map(ord, s)

l = len(s)

chalu = 10
ans = 1
for i in range (l):
    if s[i] == '?':
        if i == 0:
            ans = ans * 9
        else:
            ans = ans * 10
    elif s[i] >= '0' and s[i] <= '9':
        ans = ans * 1
    else:
        if mark [m[i]] == 0:
            mark [m[i]] = 1
            if i==0:
                ans = ans * (chalu-1)
            else:
                ans = ans * chalu
            chalu = chalu-1

print ans
