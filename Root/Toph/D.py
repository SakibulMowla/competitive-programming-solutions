if __name__ == '__main__':
  while True:
    b, p, m = [int(x) for x in raw_input().split()]  
    if b == 0 and p == 0 and m == 0:
        break
    i = 0
    n = 0
    ten = 1
    while i < 12 and b > 0:
    	i = i + 1
    	n = n + (b % 10) * ten
    	b = b / 10
    	ten = ten * 10
    print(pow(n, p, m))